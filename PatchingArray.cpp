/**
 * 330. Patching Array
 */
#include "inc/common.h"

int minPatches(vector<int>& nums, int n) {
    int count = 0;
    long long top = 0;
    int i = 0;
    while(top < n) {
        if(i < nums.size() && nums[i] <= top+1) {
            top = top+nums[i];
            i++;
        }
        else {
            count++;
            top = top*2+1;
        }
    }
    return count;
}

int main() {
    int a[] = {1,3};
    vector<int> b = arrayToVector(a);
    cout<<minPatches(b, 1)<<endl;
    return 0;
}
