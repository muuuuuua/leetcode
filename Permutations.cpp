/**
 * 46. Permutations
 */
#include "inc/common.h"

void perm(vector<int>& nums, int step, vector<vector<int> > &res) {
    if(step == nums.size()) {
        res.push_back(nums);
        return;
    }
    for(int i = step;i < nums.size();i++) {
        swap(nums[step], nums[i]);
        perm(nums, step+1, res);
        swap(nums[step], nums[i]);
    }
}

vector<vector<int> > permute(vector<int>& nums) {
    vector<vector<int> > res;
    perm(nums, 0, res);
    return res;
}

int main() {
    int a[] = {1,2,3};
    vector<int> b = arrayToVector(a);
    vector<vector<int> > r = permute(b);
    print(r);
    return 0;
}
