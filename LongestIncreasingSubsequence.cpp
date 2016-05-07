/**
 * 300. Longest Increasing Subsequence
 */
#include "inc/common.h"

int replace(vector<int>& dp, int l, int r, int x) {
    if(l >= r) {
        dp[l] = x;
        return l;
    }
    int mid = (l+r)/2;
    if(dp[mid] < x) {
        return replace(dp, mid+1, r, x);
    }
    else if(dp[mid] == x) {
        return mid;
    }
    else {
        if(mid-1 >= l && dp[mid-1] < x) {
            dp[mid] = x;
            return mid;
        }
        else {
            return replace(dp, l, mid-1, x);
        }
    }
}

int lengthOfLIS(vector<int>& nums) {
    if(nums.size() <= 1)
        return nums.size();
    vector<int> dp;
    dp.push_back(nums[0]);
    int len = 1;
    int maxL = 0;
    for(int i = 1;i < nums.size();i++) {
        if(nums[i] > dp.back()) {
            dp.push_back(nums[i]);
            len = dp.size();
        }
        else
            len = 1+replace(dp, 0, dp.size()-1, nums[i]);
        maxL = maxL > len ? maxL : len;
    }
    return maxL;
}

int main() {
    int a[] = {3,5,6,2,5,4,19,5,6,7,12};
    vector<int> b = arrayToVector(a);
    cout<<lengthOfLIS(b)<<endl;
    return 0;
}
