/**
 * 53. Maximum Subarray
 */
#include "inc/common.h"

int maxSubArray(vector<int>& nums) {
    int totalMax = INT_MIN, curMax = 0;
    int n = nums.size();
    if(n == 0) return 0;
    for(int i = 0;i < n;i++) {
        curMax += nums[i];
        totalMax = totalMax>curMax?totalMax:curMax;
        if(curMax <= 0) curMax = 0;
    }
    return totalMax;
}

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> b = arrayToVector(a);
    cout<<maxSubArray(b)<<endl;
    return 0;
}
