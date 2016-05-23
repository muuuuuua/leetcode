/**
 * 55. Jump Game
 */
#include "inc/common.h"

bool canJump(vector<int>& nums) {
    int far = 0;
    for(int i = 0;i < nums.size();i++) {
        if(i > far)
            return false;
        far = far > i+nums[i]?far:i+nums[i];
        if(far >= nums.size()-1)
            return true;
    }
    return false;
}

int main() {
    int a[] = {3,2,1,0,4};
    vector<int> n = arrayToVector(a);
    cout<<canJump(n)<<endl;
    return 0;
}
