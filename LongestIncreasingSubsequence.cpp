/**
 * 300. Longest Increasing Subsequence
 */
#include "inc/common.h"

void replace(vector<int>& dp, int l, int r, int x) {
    if(l >= r) {
        dp[l] = x;
        return;
    }
    int mid = (l+r)/2;
    if(dp[mid] == x) {
        return;
    }
    else if(dp[mid] > x) {
        replace(dp, l, mid, x);
    }
    else {
        replace(dp, mid+1, r, x);
    }
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) return n;
    vector<int> dp;
    dp.push_back(nums[0]);
    for(int i = 1;i < n;i++) {
        if(nums[i] > dp.back())
            dp.push_back(nums[i]);
        else
            replace(dp, 0, dp.size(), nums[i]);
    }
    return dp.size();
}

int main() {
    int a[] = {3,5,6,2,5,4,19,5,6,7,12};
    vector<int> b = arrayToVector(a);
    cout<<lengthOfLIS(b)<<endl;
    return 0;
}
