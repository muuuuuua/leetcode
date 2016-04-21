/**
 * 217. Contains Duplicate
 */
#include "inc/common.h"

static bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(nums.size() <= 1)
        return false;
    vector<pair<long, int> > v;
    for(int i = 0;i < nums.size();i++) {
        v.push_back(pair<long, int>(nums[i], i));
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0;i < v.size();i++) {
        for(int j = i+1;j < v.size();j++) {
            if(v[j].first - v[i].first > t) 
                break;
            if(v[j].second-v[i].second <= k && v[j].second+k >= v[i].second) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int a[] = {-1,2147483647};
    vector<int> b = arrayToVector(a);
    cout<<containsNearbyAlmostDuplicate(b, 1, 2147483647)<<endl;
    return 0;
}
