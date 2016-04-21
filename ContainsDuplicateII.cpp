/**
 * 219. Contains Duplicate II
 */
#include "inc/common.h"

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(nums.size() <= 1)
        return false;
    unordered_map<int, int> map;
    for(int i = 0;i < nums.size();i++) {
        if(map.find(nums[i]) != map.end()) { 
            if(i-map[nums[i]] <= k) {
                return true;
            }
        }
        map[nums[i]] = i;
    }
    return false;
}

int main() {
    int a[] = {1,2,3,4,1};
    vector<int> b = arrayToVector(a);
    cout<<containsNearbyDuplicate(b, 2)<<endl;
    return 0;
}
