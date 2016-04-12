/**
 * 238. Product of Array Except Self
 */
#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> output;
    output.push_back(1);
    for(int i = 0;i < nums.size()-1;i++) {
        output.push_back(output.back()*nums[i]);
    }
    int t = 1;
    for(int i = nums.size()-1;i >= 0;i--) {
        output[i] = output[i]*t;
        t *= nums[i];
    }
    return output;
}

int main() {
    int a[] = {1,2,3,4};
    vector<int> n(a, a+4);
    vector<int> b = productExceptSelf(n);
    for(int i = 0;i < b.size();i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}
