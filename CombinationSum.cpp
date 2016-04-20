/**
 * 39. Combination Sum
 */
#include "inc/common.h"

void find(int step, int now, int prev, int target, vector<int> temp, vector<int>& candidates, vector<vector<int> >& res) {
    if(now == target) {
        res.push_back(temp);
        return;
    }
    else if(now > target)
        return;
    for(int i = step;i < candidates.size();i++) {
        if(prev == candidates[i] && i != step)
            continue;
        vector<int> t = temp;
        t.push_back(candidates[i]);
        find(i, now+candidates[i], candidates[i],target, t, candidates, res);
    }
}

int partition(vector<int> &nums, int l, int r) {
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
    swap(nums[r], nums[j]);
    return j;
}

void quicksort(vector<int> &nums, int l, int r) {
    if(l >= r)
        return;
    int mid = partition(nums, l, r);
    quicksort(nums, l, mid-1);
    quicksort(nums, mid+1, r);
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > res;
    vector<int> temp;
    quicksort(candidates, 0, candidates.size()-1);
    find(0, 0, -1, target, temp, candidates, res);
    return res;
}

int main() {
    int a[] = {2,3,6,7};
    vector<int> c = arrayToVector(a, 4);
    vector<vector<int> > r = combinationSum(c, 7);
    for(int i = 0;i < r.size();i++) {
        printVector(r[i]);
    }
    return 0;
}
