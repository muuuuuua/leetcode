/**
 * 312. Burst Balloons
 */
#include "inc/common.h"

int max(int a, int b) {
    return a>b?a:b;
}

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    
    vector<vector<int> > dp(n+2, vector<int>(n+2, 0));

    for(int len = 1;len <= n;len++) {
        for(int i = 1;i <= n+1-len;i++) {
            int j = i+len-1;
            for(int k = i;k <= j;k++) {
                dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
            }
        }
    }
    return dp[1][n];
}

int main() {
    int a[] = {3,1,5,8};
    vector<int> b = arrayToVector(a);
    cout<<maxCoins(b)<<endl;
    return 0;
}
