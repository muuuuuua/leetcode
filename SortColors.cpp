/**
 * 75. Sort Colors
 */
#include "inc/common.h"

void sortColors(vector<int>& nums) {
    int start = 0, end = nums.size()-1;
    for(int i = 0;i <= end;i++) {
        if(nums[i] == 0) {
            swap(nums[i], nums[start]);
            start++;
        }
        else if(nums[i] == 2) {
            swap(nums[i], nums[end]);
            end--;
            i--;
        }
    }
}

int main() {
    int a[] = {1,2,0,1,2,1,1,1,0,0};
    vector<int> b = arrayToVector(a);
    sortColors(b);
    printVector(b);
    return 0;
}
