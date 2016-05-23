/**
 * 45. Jump Game II
 */
#include "inc/common.h"

int jump(vector<int>& nums) {
    if(nums.size() <= 1)
        return 0;
    int step = 0, start = 0, far = 0;
    while(step <= nums.size()) {
        int temp = far;
        for(int i = start;i <= temp;i++) {
            far = far > i+nums[i]?far:i+nums[i];
        }
        if(far >= nums.size()-1)
            return step+1;
        step++;
        start = temp+1;
    }
    return step;
}

int main() {
    int a[] = {1,1,1,1,1};
    vector<int> n = arrayToVector(a);
    cout<<jump(n)<<endl;
    return 0;
}
