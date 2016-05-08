/**
 * 90. Subsets II
 */
#include "inc/common.h"

void find(vector<int>& nums, int step, vector<int> temp, vector<vector<int> > &res) {
    res.push_back(temp);
    for(int i = step;i < nums.size();i++) {
        temp.push_back(nums[i]);
        find(nums, i+1, temp, res);
        temp.pop_back();
        while(i < nums.size()-1 && nums[i] == nums[i+1])
            i++;
    }
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    find(nums, 0, temp, res);
    return res;
}

int main() {
    int a[] = {1,2,1,1,2,3};
    vector<int> b = arrayToVector(a);
    vector<vector<int> > r = subsetsWithDup(b);
    for(int i = 0;i < r.size();i++) {
        printVector(r[i]);
    }
    return 0;
}

