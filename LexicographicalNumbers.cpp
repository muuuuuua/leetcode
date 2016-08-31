/**
 * 386. Lexicographical Numbers
 */

#include "inc/common.h"

void generate(int cur, int n, vector<int> &nums) {
    if(cur > n) return;
    nums.push_back(cur);
    for(int i = 0;i <= 9;i++) {
        int temp = cur*10+i;
        generate(temp, n, nums);
    }
}

vector<int> lexicalOrder(int n) {
    vector<int> nums;
    for(int i = 1;i <= 9;i++) {
        generate(i, n, nums);
    }
    return nums;
}

int main() {
    vector<int> a = lexicalOrder(999);
    print(a);
    return 0;
}