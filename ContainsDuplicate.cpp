/**
 * 217. Contains Duplicate
 */
#include "inc/common.h"

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;
    for(int i = 0;i < nums.size();i++) {
        if(map.find(nums[i]) != map.end()) 
            return true;
        map[nums[i]] = 1;
    }
    return false;
}

int main() {
    int a[] = {1,2,3,4,1};
    vector<int> b = arrayToVector(a);
    cout<<containsDuplicate(b)<<endl;
    return 0;
}
