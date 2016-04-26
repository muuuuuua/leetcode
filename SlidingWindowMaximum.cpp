/**
 * 239. Sliding Window Maximum
 */
#include "inc/common.h"

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> d;
    vector<int> res;
    if(nums.size() == 0)
        return res;
    for(int i = 0;i < k;i++) {
        if(d.empty())
            d.push_back(nums[i]);
        else {
            while(!d.empty() && nums[i] > d.back())
                d.pop_back();
            d.push_back(nums[i]);
        }
    }
    res.push_back(d.front());
    for(int i = 1;i <= nums.size()-k;i++) {
        int pass = nums[i-1];
        if(pass == d.front())
            d.pop_front();
        while(!d.empty() && nums[i+k-1] > d.back())
            d.pop_back();
        d.push_back(nums[i+k-1]);
        res.push_back(d.front());
    }
    return res;
}

int main() {
    int a[] = {1,-1};
    vector<int> b = arrayToVector(a);
    vector<int> r = maxSlidingWindow(b, 1);
    printVector(r);
    return 0;
}
