/**
 * 343. Integer Break
 */
#include "inc/common.h"

int integerBreak(int n) {
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= i-j;j++) {
            int t1 = dp[j] > j?dp[j]:j;
            int t2 = dp[i-j]>i-j?dp[i-j]:i-j;
            dp[i] = t1*t2>dp[i]?t1*t2:dp[i];
        }
    }
    return dp[n];
}

int main() {
    cout<<integerBreak(5)<<endl;
    return 0;
}
