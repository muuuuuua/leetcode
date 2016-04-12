/**
 * 213. House Robber II
 */
#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
    return a>b?a:b;
}

int rob(vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return nums[0];
    if(nums.size() == 2)
        return max(nums[0], nums[1]);
    if(nums.size() == 3)
        return max(max(nums[0], nums[1]), nums[2]);
    int *dp = new int[nums.size()];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2;i < nums.size()-1;i++) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    int res = dp[nums.size()-2];
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for(int i = 3;i < nums.size();i++) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    res = max(res, dp[nums.size()-1]);
    delete []dp;
    return res;
}

int main() {
    int a[] = {3,0,6,1,5};
    vector<int> c(a, a+5);
    cout<<rob(c)<<endl;
    return 0;
}
