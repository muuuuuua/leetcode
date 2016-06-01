/**
 * 315. Count of Smaller Numbers After Self
 */
#include "inc/common.h"

class FenwickTree {
private:
    int lowbit(int x) { 
        return x&(-x);
    }
    vector<int> count;
    int n;
public:
    FenwickTree(int size):n(size) {
        count = vector<int>(n+1, 0);
    }
    int sum(int x) {
        int ans = 0;
        while(x > 0) {
            ans += count[x];
            x -= lowbit(x);
        }
        return ans;
    }
    void update(int x, int val) {
        while(x <= n) {
            count[x] += val;
            x += lowbit(x);
        }
    }
};

vector<int> countSmaller(vector<int>& nums) {
    vector<int> res;
    if(nums.size() == 0) return res;
    FenwickTree tree(nums.size());
    res = vector<int>(nums.size(), 0);
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> map;
    for(int i = 0;i < temp.size();i++)
        map[temp[i]] = i+1;
    for(int i = nums.size()-1;i >= 0;i--) {
        res[i] = tree.sum(map[nums[i]]-1);
        tree.update(map[nums[i]], 1);
    }
    return res;
}

int main() {
    int a[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    vector<int> b = arrayToVector(a);
    vector<int> c = countSmaller(b);
    print(c);
    return 0;
}
