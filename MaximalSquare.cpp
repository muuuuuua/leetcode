/**
 * 221. Maximal Square
 */
#include "inc/common.h"

int min(int a, int b, int c) {
    if(a < b)
        return a<c?a:c;
    else
        return b<c?b:c;
}

int max(int a, int b) {
    return a>b?a:b;
}

int maximalSquare(vector<vector<char> >& matrix) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int> > v(m, vector<int>(n, 0));
    vector<vector<int> > h(m, vector<int>(n, 0));
    vector<vector<int> > dp(m, vector<int>(n, 0));
    int maxLen = 0;
    for(int i = 0;i < m;i++) {
        v[i][0] = matrix[i][0]-'0';
        for(int j = 1;j < n;j++) {
            if(matrix[i][j] == '0')
                v[i][j] = 0;
            else
                v[i][j] = v[i][j-1]+1;
        }
    }
    for(int i = 0;i < n;i++) {
        h[0][i] = matrix[0][i]-'0';
        for(int j = 1;j < m;j++) {
            if(matrix[j][i] == '0')
                h[j][i] = 0;
            else
                h[j][i] = h[j-1][i]+1;
        }
    }
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            if(matrix[i][j] == '0')
                continue;
            if(i-1 >= 0 && j-1 >= 0 && dp[i-1][j-1] != 0) {
                int l = dp[i-1][j-1];
                int lv = v[i][j];
                int lh = h[i][j];
                int len = min(l+1, lv, lh);
                dp[i][j] = len;
            }
            else {
                dp[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            maxLen = max(maxLen, dp[i][j]);
        }
    }
    return maxLen*maxLen;
}

int main() {
    vector<vector<char> > matrix;
    int a[][5] = {{1,0,1,0,0},
                  {1,0,1,1,1},
                  {1,1,1,1,1},
                  {1,0,0,1,0}};
    for(int i = 0;i < 4;i++) {
        vector<char> t;
        for(int j = 0;j < 5;j++)
            t.push_back(a[i][j]+'0');
        matrix.push_back(t);
    }
    cout<<maximalSquare(matrix)<<endl;
    return 0;
}
