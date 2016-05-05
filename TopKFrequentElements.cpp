/**
 * 347. Top K Frequent Elements
 */
#include "inc/common.h"

static bool comp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second;
}

vector<int> topKFrequent(vector<int> &nums, int k) {
    vector<int> res;
    if(nums.size() == 0 || k == 0) {
        return res;
    }
    unordered_map<int, int> fre;
    for(int i = 0;i < nums.size();i++) {
        if(fre.find(nums[i]) == fre.end())
            fre[nums[i]] = 1;
        else
            fre[nums[i]]++;
    }
    vector<pair<int, int> > temp;
    for(int i = 0;i < nums.size();i++) {
        int num = nums[i];
        int f = fre[num];
        if(f > 0) {
            temp.push_back(pair<int,int>(num,f));
            fre[num] = 0;
        }
    }
    sort(temp.begin(), temp.end(), comp);
    for(int i = 0;i < k;i++) {
        res.push_back(temp[i].first);
    }
    return res;
}

int main() {
    int a[] = {1,1,1,2,2,3};
    vector<int> b = arrayToVector(a);
    vector<int> r = topKFrequent(b, 2);
    printVector(r);
    return 0;
}

