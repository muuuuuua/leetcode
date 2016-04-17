/**
 * 169. Majority Element 
 */
#include "inc/common.h"

int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int count = 1;
    for(int i = 1;i < nums.size();i++) {
        if(nums[i] == candidate)
            count++;
        else {
            if(count == 0) {
                count = 1;
                candidate = nums[i];
            }
            else
                count--;
        }
    }
    return candidate;
}

int main() {
    int a[] = {1,2,3};
    vector<int> b = arrayToVector(a, 3);
    cout<<majorityElement(b)<<endl;
    return 0;
}
