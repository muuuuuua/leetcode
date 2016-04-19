/**
 * 334. Increasing Triplet Subsequence
 */
#include "inc/common.h"

bool increasingTriplet(vector<int>& nums) {
    if(nums.size() < 3)
        return false;
    vector<int> dp(nums.size(), 1);
    for(int k = 1;k < nums.size();k++) {
        for(int i = 0;i < k;i++) {
            if(nums[i] < nums[k])
                dp[k] = dp[i]+1>dp[k]?dp[i]+1:dp[k];
        }
        if(dp[k] >= 3)
            return true;
    }
    return false;
}

int main() {
    int a[] = {1,2,-10,-8,-7};
    vector<int> b = arrayToVector(a, 5);
    cout<<increasingTriplet(b)<<endl;
    return 0;
}
