/**
 * 209. Minimum Size Subarray Sum
 */
#include "inc/common.h"

int min(int a, int b) {
    return a < b ? a : b;
}

int minSubArrayLen(int s, vector<int>& nums) {
    int sum = 0;
    int len = nums.size()+1;
    int start = 0;
    for(int i = 0;i < nums.size();i++) {
        sum += nums[i];
        while(sum >= s) {
            len = min(len, i-start+1);
            sum -= nums[start];
            start++;
        }
    }
    return len<=nums.size()?len:0;
}

int main() {
    int a[] = {2,3,1,2,4,3};
    vector<int> b = arrayToVector(a, 6);
    cout<<minSubArrayLen(7, b)<<endl;
    return 0;
}
