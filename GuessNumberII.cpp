/**
 * 375. Guess Number Higher or Lower II
 */
#include "inc/common.h"

int getMoneyAmount(int n) {
    vector<vector<int> > dp(n+1, vector<int>(n+1,0));
    for(int i = n-1;i >= 1;i--) {
        for(int j = i+1;j <= n;j++) {
            dp[i][j] = INT_MAX;
            for(int k = i;k < j;k++) {
                dp[i][j] = min(dp[i][j],k+max(dp[i][k-1],dp[k+1][j]));
            }
        }
    }
    return dp[1][n];
}

int main() {
    cout<<getMoneyAmount(7)<<endl;
    return 0;
}