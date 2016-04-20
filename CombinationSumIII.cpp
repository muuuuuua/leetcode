/**
 * 216. Combination Sum III
 */
#include "inc/common.h"

void find(int step, int now, int count, int k, int target, vector<int> temp, vector<int>& candidates, vector<vector<int> >& res) {
    if(now == target && count == k) {
        res.push_back(temp);
        return;
    }
    else if(now > target || count >= k)
        return;
    for(int i = step;i < candidates.size();i++) {
        if(i != step && candidates[i] == candidates[i-1])
            continue;
        vector<int> t = temp;
        t.push_back(candidates[i]);
        find(i+1, now+candidates[i], count+1, k, target, t, candidates, res);
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > res;
    vector<int> candidates;
    for(int i = 1;i <= 9;i++) {
        candidates.push_back(i);
    }
    vector<int> temp;
    find(0, 0, 0, k, n, temp, candidates, res);
    return res;
}

int main() {
    vector<vector<int> > r = combinationSum3(3, 9);
    for(int i = 0;i < r.size();i++) {
        printVector(r[i]);
    }
    return 0;
}
