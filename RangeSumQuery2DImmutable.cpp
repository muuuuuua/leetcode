/**
 * 304. Range Sum Query 2D - Immutable
 */
#include "inc/common.h"

class NumMatrix {
private:
    vector<vector<int> > hSum;
public:
    NumMatrix(vector<vector<int> > &matrix) {
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

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1;i <= row2;i++) {
            sum += (hSum[i][col2+1] - hSum[i][col1]);
        }
        return sum;
    }
};

int main() {

}
