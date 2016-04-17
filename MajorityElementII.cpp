/**
 * 229. Majority Element II
 */
#include "inc/common.h"

vector<int> majorityElement(vector<int>& nums) {
    int candidate[2] = {0};
    int count[2] = {0};
    for(int i = 0;i < nums.size();i++) {
        int temp = nums[i];
        if(candidate[0] != temp && candidate[1] != temp) {
            if(count[0] != 0 && count[1] != 0) {
                count[0]--;
                count[1]--;
            }
            else if(count[0] == 0) {
                count[0] = 1;
                candidate[0] = temp;
            }
            else {
                count[1] = 1;
                candidate[1] = temp;
            }
        }
        else if(candidate[0] == temp) {
            count[0]++;
        }
        else {
            count[1]++;
        }
    }
    vector<int> res;
    int n = nums.size();
    for(int i = 0;i < 2;i++) {
        if(count[i] > 0) {
            int t = 0;
            for(int j = 0;j < n;j++) {
                if(nums[j] == candidate[i])
                    t++;
            }
            if(t > n/3)
                res.push_back(candidate[i]);
        }
    }
    return res;
}

int main() {
    int a[] = {1,2,3};
    vector<int> b = arrayToVector(a, 3);
    vector<int> r = majorityElement(b);
    printVector(r);
    return 0;
}
