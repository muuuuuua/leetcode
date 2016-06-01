/**
 * 164. Maximum Gap
 */
#include "inc/common.h"

int maximumGap(vector<int>& nums) {
    if(nums.size() <= 1) return 0;
    int maxn = nums[0], minn = nums[0];
    for(int i = 1;i < nums.size();i++) {
        maxn = max(maxn, nums[i]);
        minn = min(minn, nums[i]);
    }
    if(maxn == minn) return 0;
    int len = (maxn-minn)/(nums.size()-1)+1;
    vector<vector<int> > bucket(nums.size(), vector<int>(2,0));
    for(int i = 0;i < nums.size();i++) {
        bucket[i][0] = INT_MIN;
        bucket[i][1] = INT_MAX;
    }
    for(int i = 0;i < nums.size();i++) {
        int loc = (nums[i]-minn)/len;
        bucket[loc][0] = max(bucket[loc][0], nums[i]);
        bucket[loc][1] = min(bucket[loc][1], nums[i]);
    }
    int gap = 0, prev = 0;
    for(int i = 0;i < nums.size();i++) {
        if(bucket[i][0] == INT_MIN || bucket[i][1] == INT_MAX)
            continue;
        gap = max(gap, bucket[i][1]-bucket[prev][0]);
        gap = max(gap, bucket[i][0]-bucket[i][1]);
        prev = i;
    }
    return gap;
}

int main() {
    int a[] = {1,11111};
    vector<int> b = arrayToVector(a);
    cout<<maximumGap(b)<<endl;
    return 0;
}
