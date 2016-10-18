/**
 * 398. Random Pick Index
 */
#include "inc/common.h"

class Solution {
private:
    vector<int> record;
public:
    Solution(vector<int> nums) {
        srand(time(NULL));
        record = nums;
    }
    
    int pick(int target) {
        int count = 1;
        int index = -1;
        for(int i = 0;i < record.size();i++) {
            if(record[i] != target)
                continue;
            else if(rand()%(count++) == 0) {
                index = i;
            }
        }
        return index;
    }
};

int main() {
    int a[] = {1,2,3,3,3};
    vector<int> nums = arrayToVector(a);
    Solution obj(nums);
    cout<<obj.pick(3)<<endl;
    return 0;
}
