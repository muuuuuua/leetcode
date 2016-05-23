/**
 * 42. Trapping Rain Water
 */
#include "inc/common.h"

int trap(vector<int>& height) {
    int n = height.size();
    if(n <= 2)
        return 0;
    vector<int> l(n, 0), r(n, 0);
    for(int i = 1;i < n;i++) {
        l[i] = l[i-1]>height[i-1]?l[i-1]:height[i-1];
    }
    for(int i = n-2;i >= 0;i--) {
        r[i] = r[i+1]>height[i+1]?r[i+1]:height[i+1];
    }
    int sum = 0;
    for(int i = 0;i < n;i++) {
        int min = l[i]<r[i]?l[i]:r[i];
        if(min > height[i])
            sum += min-height[i];
    }
    return sum;
}

int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> b = arrayToVector(a);
    cout<<trap(b)<<endl;
    return 0;
}