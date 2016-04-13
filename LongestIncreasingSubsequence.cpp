/**
 * 300. Longest Increasing Subsequence
 */
#include "inc/common.h"

int max(int a, int b) {
    return a>b?a:b;
}

int lengthOfLIS(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    vector<int> dp(nums.size());
    dp[0] = 1;
    for(int i = 1;i < nums.size();i++) {
        int len = 1;
        for(int j = 0;j < i;j++) {
            if(nums[j] < nums[i])
                len = max(dp[j]+1, len);
        }
        dp[i] = len;
    }
    int res = 0;
    for(int i = 0;i < dp.size();i++)
        res = max(res, dp[i]);
    return res;
}

int main() {
    int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> b = arrayToVector(a, 8);
    cout<<lengthOfLIS(b)<<endl;
    return 0;
}
