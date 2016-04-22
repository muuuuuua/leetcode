/**
 * 260. Single Number III
 */
#include "inc/common.h"

vector<int> singleNumber(vector<int>& nums) {
    int axorb = 0;
    for(int i = 0;i < nums.size();i++)
        axorb ^= nums[i];
    int mask = axorb & ~(axorb - 1);
    int a = 0, b = 0;
    for(int i = 0;i < nums.size();i++) {
        if(nums[i] & mask)
            a ^= nums[i];
        else
            b ^= nums[i];
    }
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    return res;
}

int main() {
    int a[] = {1,2,1,3,2,5};
    vector<int> b = arrayToVector(a);
    vector<int> r = singleNumber(b);
    printVector(r);
    return 0;
}
