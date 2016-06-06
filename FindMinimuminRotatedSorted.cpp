/**
 * 153. Find Minimum in Rotated Sorted
 */
#include "inc/common.h"

int find(vector<int> &nums, int l, int r) {
    if(r - l <= 1)
        return nums[l]<nums[r]?nums[l]:nums[r];
    if(nums[r] > nums[l]) return nums[l];
    int mid = (l+r)/2;
    if(nums[mid] > nums[l])
        return find(nums, mid, r);
    else
        return find(nums, l, mid);
}

int findMin(vector<int> &nums) {
    int n = nums.size();
    if(n == 0) return 0;
    return find(nums, 0, n-1);
}

int main() {
    int a[] = {4,5,6,7,0,1,2};
    vector<int> b = arrayToVector(a);
    cout<<findMin(b)<<endl;
    return 0;
}
