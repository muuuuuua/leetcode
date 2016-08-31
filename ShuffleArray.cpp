/**
 * 384. Shuffle an Array
 */

#include "inc/common.h"

class Solution {
private:
    vector<int> origin;
public:
    Solution(vector<int> nums) {
        origin = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> shuffle(origin.size(), 0);
        vector<int> index;
        for(int i = 0;i < origin.size();i++) {
            index.push_back(i);
        }
        int i = 0;
        while(index.size() > 0) {
            int r = rand()%index.size();
            shuffle[index[r]] = origin[i];
            i++;
            index[r] = index.back();
            index.pop_back();
        }
        return shuffle;
    }
};

int main() {
    int a[] = {1,2,3};
    vector<int> nums = arrayToVector(a);
    Solution obj = Solution(nums);
    print(obj.reset());
    print(obj.shuffle());
    return 0;
}