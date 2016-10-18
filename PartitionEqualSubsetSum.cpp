/**
 * 416. Partition Equal Subset Sum
 */
#include "inc/common.h"

bool canPartition(vector<int> &nums) {
    int sum = 0;
    for(int i = 0;i < nums.size();i++) {
        sum += nums[i];
    }
    if(sum % 2 != 0) return false;
    int c = sum / 2;
    vector<bool> dp(c+1, false);
    dp[0] = true;
    for(int i = 0;i < nums.size();i++) {
        for(int v = c;v >= 0;v--) {
            if(v - nums[i] >= 0 && dp[v-nums[i]] == true)
                dp[v] = true;
        }
    }
    return dp[c];
}

int main() {
    int a[] = {1,5,11,11};
    vector<int> b = arrayToVector(a);
    cout<<canPartition(b)<<endl;
    return 0;
}
