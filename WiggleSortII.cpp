/**
 * 324. Wiggle Sort II
 */
#include "inc/common.h"

int partition(vector<int>& nums, int l, int r) {
    if(l >= r)
        return l;
    int x = nums[r];
    int j = l;
    for(int i = l;i < r;i++) {
        if(nums[i] < x) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
    swap(nums[j], nums[r]);
    return j;
}

int findMedium(vector<int>& nums, int l, int r) {
    if(l >= r)
        return l;
    int mid = partition(nums, l, r);
    if(mid == nums.size()/2)
        return mid;
    else if(mid > nums.size()/2)
        return findMedium(nums, l, mid-1);
    else
        return findMedium(nums, mid+1, r);
}

int virtual_index(int idx, int n) {
    return (2*idx+1)%(n|1);
}

void wiggleSort(vector<int>& nums) {
    int mediumIndex = findMedium(nums, 0, nums.size()-1);
    int i = 0, j = 0, k = nums.size()-1;
    int mid = nums[mediumIndex];
    while(j <= k) {
        if(nums[virtual_index(j, nums.size())] > mid) {
            swap(nums[virtual_index(i, nums.size())], nums[virtual_index(j, nums.size())]);
            i++;
            j++;
        }
        else if(nums[virtual_index(j, nums.size())] < mid) {
            swap(nums[virtual_index(k, nums.size())], nums[virtual_index(j, nums.size())]);
            k--;
        }
        else
            j++;
    }
}

int main() {
    int a[] = {1,3,2,2,3,1};
    vector<int> b = arrayToVector(a, 6);
    wiggleSort(b);
    printVector(b);
    return 0;
}
