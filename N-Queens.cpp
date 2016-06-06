/**
 * 51. N-Queens
 */
#include "inc/common.h"

void place(int n, int step, vector<bool> &col, vector<bool> &dia1, vector<bool> &dia2, vector<int> &record, vector<vector<string> > &res) {
    if(step >= n) {
        vector<string> temp;
        for(int i = 0;i < n;i++) {
            string s = "";
            for(int j = 0;j < n;j++) {
                if(j != record[i])
                    s += '.';
                else
                    s += 'Q';
            }
            temp.push_back(s);
        }
        res.push_back(temp);
        return;
    }
    for(int i = 0;i < n;i++) {
        if(!col[i] && !dia1[i+step] && !dia2[step+n-i-1]) {
            col[i] = true;
            dia1[step+i] = true;
            dia2[step+n-i-1] = true;
            record[step] = i;
            place(n, step+1, col, dia1, dia2, record, res);
            record[step] = 0;
            col[i] = false;
            dia1[step+i] = false;
            dia2[step+n-i-1] = false;
        }
    }
}

vector<vector<string> > solveNQueens(int n) {
    vector<vector<string> > res;
    vector<int> record(n, -1);
    vector<bool> col(n, false);
    vector<bool> dia1(2*n-1, false);
    vector<bool> dia2(2*n-1, false);
    place(n, 0, col, dia1, dia2, record, res);
    return res;
}

int main() {
    vector<vector<string> > r = solveNQueens(8);
    print(r);
    return 0;
}
