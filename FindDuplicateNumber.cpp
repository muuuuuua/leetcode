/**
 * 287. Find the Duplicate Number
 */
#include "inc/common.h"

int find(vector<int>& nums, int start, int end) {
    if(start == end)
        return start;
    int mid = (start+end)/2;
    int lt = 0, gt = 0, eq = 0;
    for(int i = 0;i < nums.size();i++) {
        if(nums[i] < mid)
            lt++;
        else if(nums[i] > mid)
            gt++;
        else
            eq++;
    }
    if(eq > 1)
        return mid;
    else if(lt < mid)
        return find(nums, mid+1, end);
    else
        return find(nums, start, mid-1);
}

int findDuplicate(vector<int>& nums) {
    return find(nums, 1, nums.size()-1);
}

int main() {
    int a[] = {1,2,2};
    vector<int> b = arrayToVector(a, 5);
    cout<<findDuplicate(b)<<endl;
    return 0;
}
