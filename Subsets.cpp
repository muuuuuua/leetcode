/**
 * 78. Subsets
 */
#include "inc/common.h"

void find(vector<int>& nums, int step, vector<int> temp, vector<vector<int> > &res) {
    if(step == nums.size()) {
        res.push_back(temp);
        return;
    }
    find(nums, step+1, temp, res);
    temp.push_back(nums[step]);
    find(nums, step+1, temp, res);
}

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    find(nums, 0, temp, res);
    return res;
}

int main() {
    int a[] = {1,2,3};
    vector<int> b = arrayToVector(a);
    vector<vector<int> > r = subsets(b);
    for(int i = 0;i < r.size();i++) {
        printVector(r[i]);
    }
    return 0;
}

