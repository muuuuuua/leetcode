/**
 * 198. House Robber
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
    int *dp = new int[nums.size()];
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2;i < nums.size();i++) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }
    int res = dp[nums.size()-1];
    delete []dp;
    return res;
}

int main() {
    int a[] = {3,0,6,1,5};
    vector<int> c(a, a+5);
    cout<<rob(c)<<endl;
    return 0;
}
