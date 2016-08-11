/**
 * 376. Wiggle Subsequence
 */
#include "inc/common.h"

int wiggleMaxLength(vector<int>& nums) {
    if(nums.size() <= 1) return nums.size();
    vector<int> big(nums.size(), 0);
    vector<int> small(nums.size(), 0);
    big[0] = 1;
    small[0] = 1;
    for(int i = 1;i < nums.size();i++) {
        if(nums[i] > nums[i-1]) {
            big[i] = small[i-1]+1;
            small[i] = small[i-1];
        }
        else if(nums[i] < nums[i-1]) {
            big[i] = big[i-1];
            small[i] = big[i-1]+1;
        }
        else {
            big[i] = big[i-1];
            small[i] = small[i-1];
        }
    }
    return max(big[nums.size()-1], small[nums.size()-1]);
}

int main() {
    int a[] = {0,0};
    vector<int> n = arrayToVector(a);
    cout<<wiggleMaxLength(n)<<endl;
}