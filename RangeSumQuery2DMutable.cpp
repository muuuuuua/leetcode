/**
 * 308. Range Sum Query 2D - Mutable
 */
#include "inc/common.h"

class NumMatrixWithoutTree {
private:
    vector<vector<int> > hSum;
public:
    NumMatrixWithoutTree(vector<vector<int> > &matrix) {
        if(matrix.size() == 0)
            return;
        int n = matrix.size();
        int m = matrix[0].size();
        hSum = vector<vector<int> >(n, vector<int>(m+1, 0));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++)
                hSum[i][j+1] = hSum[i][j] + matrix[i][j];
        }
    }

    void update(int row, int col, int val) {
        int origin = hSum[row][col+1] - hSum[row][col];
        int diff = val - origin;
        for(int j = col+1;j < hSum[row].size();j++) {
            hSum[row][j] += val;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1;i <= row2;i++) {
            sum += (hSum[i][col2+1] - hSum[i][col1]);
        }
        return sum;
    }
};

class SegTreeNode2D {
public:
    SegTreeNode2D *lt, *lb, *rt, *rb;
    int lridx, lcidx, rridx, rcidx;
    int sum;
    SegTreeNode2D(vector<vector<int> > &matrix, int lrow, int lcol, int rrow, int rcol) {
        if(lrow > rrow || lcol > rcol) {
            sum = 0;
            lt = lb = rt = rb = NULL;
        }
        else {
            lridx = lrow;
            lcidx = lcol;
            rridx = rrow;
            rcidx = rcol;
            if(lrow == rrow && lcol == rcol) {
                sum = matrix[lrow][lcol];
                lt = lb = rt = rb = NULL;
            }
            else {
                int midrow = (lrow+rrow)/2;
                int midcol = (lcol+rcol)/2;
                lt = new SegTreeNode2D(matrix, lrow, lcol, midrow, midcol);
                lb = new SegTreeNode2D(matrix, midrow+1, lcol, rrow, midcol);
                rt = new SegTreeNode2D(matrix, lrow, midcol+1, midrow, rcol);
                rb = new SegTreeNode2D(matrix, midrow+1, midcol+1, rrow, rcol);
                sum = lt->sum+lb->sum+rt->sum+rb->sum;
            }
        }
    }

};


class NumMatrix {
private:
    SegTreeNode2D *root;
    void update(int row, int col, int val, SegTreeNode2D *r) {
        if(r->lridx == r->rridx && r->lcidx == r->rcidx && row == r->lridx && col == r->lcidx) {
            r->sum = val;
            return;
        }
        int midrow = (r->lridx+r->rridx)/2;
        int midcol = (r->lcidx+r->rcidx)/2;
        if(row <= midrow && col <= midcol) {
            r->sum -= r->lt->sum;
            update(row, col, val, r->lt);
            r->sum += r->lt->sum;
        }
        else if(row <= midrow && col > midcol) {
            r->sum -= r->rt->sum;
            update(row, col, val, r->rt);
            r->sum += r->rt->sum;
        }
        else if(row > midrow && col <= midcol) {
            r->sum -= r->lb->sum;
            update(row, col, val, r->lb);
            r->sum += r->lb->sum;
        }
        else {
            r->sum -= r->rb->sum;
            update(row, col, val, r->rb);
            r->sum += r->rb->sum;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2, SegTreeNode2D *r) {
        if(r->lridx == row1 && r->lcidx == col1 && r->rridx == row2 && r->rcidx == col2)
            return r->sum;
        int midrow = (r->lridx+r->rridx)/2;
        int midcol = (r->lcidx+r->rcidx)/2;
        if(row1 <= midrow) {    // top half
            if(col1 <= midcol) {    // left top
                if(row2 <= midrow && col2 <= midcol) {
                    return sumRegion(row1, col1, row2, col2, r->lt);
                }
                else if(row2 <= midrow && col2 > midcol) {
                    return sumRegion(row1, col1, row2, midcol, r->lt)
                            + sumRegion(row1, midcol+1, row2, col2, r->rt);
                }
                else if(row2 > midrow && col2 <= midcol) {
                    return sumRegion(row1, col1, midrow, col2, r->lt)
                            + sumRegion(midrow+1, col1, row2, col2, r->lb);
                }
                else {
                    return sumRegion(row1, col1, midrow, midcol, r->lt)
                            + sumRegion(midrow+1, col1, row2, midcol, r->lb)
                            + sumRegion(row1, midcol+1, midrow, col2, r->rt)
                            + sumRegion(midrow+1, midcol+1, row2, col2, r->rb);
                }
            }
            else {  // right top
                if(row2 <= midrow) {
                    return sumRegion(row1, col1, row2, col2, r->rt);
                }
                else {
                    return sumRegion(row1, col1, midrow, col2, r->rt)
                            + sumRegion(midrow+1, col1, row2, col2, r->rb);
                }
            }
        }
        else {  // bottom half
            if(col1 <= midcol) {    // left bottom
                if(col2 <= midcol) {
                    return sumRegion(row1, col1, row2, col2, r->lb);
                }
                else {
                    return sumRegion(row1, col1, row2, midcol, r->lb)
                            + sumRegion(row1, midcol+1, row2, col2, r->rb);
                }
            }
            else {  // right bottom
                return sumRegion(row1, col1, row2, col2, r->rb);
            }
        }
    }

public:
    NumMatrix(vector<vector<int> > &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return;
        root = new SegTreeNode2D(matrix, 0, 0, matrix.size()-1, matrix[0].size()-1);
    }

    void update(int row, int col, int val) {
        update(row, col, val, root);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sumRegion(row1, col1, row2, col2, root);
    }
};

int main() {
    int a[5][5] = {{3,0,1,4,2},
                    {5,6,3,2,1},
                    {1,2,0,1,5},
                    {4,1,0,1,7},
                    {1,0,3,0,5}};
    vector<vector<int> > matrix;            
    for(int i = 0;i < 5;i++) {
        vector<int> t = arrayToVector(a[i]);
        matrix.push_back(t);
    }
    NumMatrix numMatrix(matrix);
    cout<<numMatrix.sumRegion(2, 1, 4, 3)<<endl;
    cout<<numMatrix.sumRegion(1, 1, 2, 2)<<endl;
    cout<<numMatrix.sumRegion(1, 2, 2, 4)<<endl;
    numMatrix.update(3,2,2);
    cout<<numMatrix.sumRegion(2, 1, 4, 3)<<endl;
    return 0;
}
