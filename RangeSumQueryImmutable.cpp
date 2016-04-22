/**
 * 303. Range Sum Query - Immutable
 */
#include "inc/common.h"

class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        sum = vector<int>(n+1, 0);
        for(int i = 0;i < n;i++) {
            sum[i+1] = sum[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return sum[j+1]-sum[i];
    }
};

int main() {
    int a[] = {-2, 0, 3, -5, 2, -1};
    vector<int> nums = arrayToVector(a);
    NumArray numArray(nums);
    cout<<numArray.sumRange(0, 2)<<endl;
    cout<<numArray.sumRange(2, 5)<<endl;
    return 0;
}