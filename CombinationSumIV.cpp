/**
 * 377. Combination Sum IV
 */
#include "inc/common.h"

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    for(int c = 1;c <= target;c++) {
        for(int i = 0;i < nums.size();i++) {
            if(c >= nums[i])
                dp[c] += dp[c-nums[i]];
        }
    }
    return dp[target];
}

int main() {
    int a[] = {1,2,3};
    vector<int> nums = arrayToVector(a);
    cout<<combinationSum4(nums, 4)<<endl;
    return 0;
}