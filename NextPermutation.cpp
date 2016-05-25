/**
 * 31. Next Permutation
 */
#include "inc/common.h"

void reverse(vector<int>& nums, int start, int end) {
    for(int i = start;i <= (start+end)/2;i++) {
        swap(nums[i], nums[start+end-i]);
    }
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) return;
    int index = 0;
    for(int i = n-1;i > 0;i--) {
        if(nums[i] > nums[i-1]) {
            index =  i;
            break;
        }
    }
    if(index == 0) {
        reverse(nums, 0, n-1);
        return;
    }
    int sw = index;
    for(int i = n-1;i > index;i--) {
        if(nums[i] > nums[index-1]) {
            sw = i;
            break;
        }
    }
    swap(nums[sw], nums[index-1]);
    reverse(nums, index, n-1);
}

int main() {
    int a[] = {1,3,2};
    vector<int> b = arrayToVector(a);
    nextPermutation(b);
    print(b);
    return 0;
}
