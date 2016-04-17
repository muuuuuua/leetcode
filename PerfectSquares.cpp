/**
 * 279. Perfect Squares
 */
#include "inc/common.h"

vector<int> generateSquares(int n) {
    vector<int> res;
    for(int i = 1;i*i <= n;i++) {
        res.push_back(i*i);
    }
    return res;
}

int min(int a, int b) {
    return a<b?a:b;
}

int numSquares(int n) {
    vector<int> squares = generateSquares(n);
    vector<int> nums(n+1);
    nums[0] = 0;
    for(int i = 1;i < nums.size();i++) {
        nums[i] = 9999999;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < squares.size();j++) {
            if(i - squares[j] >= 0)
                nums[i] = min(nums[i], nums[i-squares[j]]+1);
        }
    }
    return nums[n];
}

int main() {
    cout<<numSquares(13)<<endl;;
    return 0;
}
