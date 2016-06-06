/**
 * 52. N-Queens II
 */
#include "inc/common.h"

void place(int n, int step, vector<bool> &col, vector<bool> &dia1, vector<bool> &dia2, int &count) {
    if(step >= n) {
        count++;
        return;
    }
    for(int i = 0;i < n;i++) {
        if(!col[i] && !dia1[i+step] && !dia2[step+n-i-1]) {
            col[i] = true;
            dia1[step+i] = true;
            dia2[step+n-i-1] = true;
            place(n, step+1, col, dia1, dia2, count);
            col[i] = false;
            dia1[step+i] = false;
            dia2[step+n-i-1] = false;
        }
    }
}

int totalNQueens(int n) {
    int count = 0;
    vector<bool> col(n, false);
    vector<bool> dia1(2*n-1, false);
    vector<bool> dia2(2*n-1, false);
    place(n, 0, col, dia1, dia2, count);
    return count;
}

int main() {
    cout<<totalNQueens(13)<<endl;
    return 0;
}
