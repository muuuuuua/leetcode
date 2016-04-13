/**
 * 315. Count of Smaller Numbers After Self
 */
#include "inc/common.h"

vector<int> countSmaller(vector<int>& nums) {
    vector<int> res = nums;
    res[nums.size()-1] = 0;
    for(int i = nums.size()-1;i >= 0;i--) {
        
    }
}

int main() {
    int a[] = {5,2,6,1};
    vector<int> b = arrayToVector(a, 4);
    vector<int> c = countSmaller(b);
    printVector(c);
    return 0;
}
