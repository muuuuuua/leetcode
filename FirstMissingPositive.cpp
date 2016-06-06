/**
 * 41. First Missing Positive
 */
#include "inc/common.h"

int firstMissingPositive(vector<int> &nums) {
    int n = nums.size();
    for(int i = 0;i < n;i++) {
        if(nums[i] <= 0) nums[i] = -(n+1);
        else if(nums[i] > 0) nums[i] = -nums[i];
    }
    for(int i = 0;i < n;i++) {
        int t;
        if(nums[i] > 0) t = nums[i];
        else t = -nums[i];
        t--;
        if(t >= 0 && t < n) {
            if(nums[t] < 0)
                nums[t] = -nums[t];
        }
    }
    for(int i = 0;i < n;i++) {
        if(nums[i] < 0) return i+1;
    }
    return n+1;
}

int main() {
    int a[] = {1,2,0};
    vector<int> b = arrayToVector(a);
    cout<<firstMissingPositive(b)<<endl;
    return 0;
}
