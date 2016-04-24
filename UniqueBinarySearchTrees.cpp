/**
 * 96. Unique Binary Search Trees
 */
#include "inc/common.h"

int numTrees(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i <= n;i++) {
        for(int j = 0;j <= i-1;j++) {
            dp[i] += dp[j]*dp[i-1-j];
        }
    }
    return dp[n];
}

int main() {
    cout<<numTrees(3)<<endl;
    return 0;
}
