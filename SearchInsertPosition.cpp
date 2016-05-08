/**
 * 35. Search Insert Position
 */
#include "inc/common.h"

int find(vector<int>& nums, int l, int r, int target) {
    if(target > nums[r])
        return r+1;
    if(l >= r)
        return l;
    int mid = (l+r)/2;
    if(nums[mid] == target)
        return mid;
    else if(nums[mid] < target) 
        return find(nums, mid+1, r, target);
    else {
        if(mid-1 < l || nums[mid-1] < target)
            return mid;
        return find(nums, l, mid-1, target);
    }
}

int searchInsert(vector<int>& nums, int target) {
    if(nums.size() == 0)
        return 0;
    return find(nums, 0, nums.size()-1, target);
}

int main() {
    int a[] = {1,3,5,6};
    vector<int> b = arrayToVector(a);
    cout<<searchInsert(b, 7)<<endl;
    return 0;
}
