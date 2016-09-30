/**
 * 396. Rotate Function
 */

#include "inc/common.h"

int maxRotateFunction(vector<int>& A) {
    int n = A.size();
    if(n <= 1) return 0;
    int res = INT_MIN;
    int sum = 0, fprev = 0;
    for(int i = 0;i < n;i++) {
        sum += A[i];
        fprev += i*A[i];
    }
    res = max(fprev, res);
    for(int i = 1;i < n;i++) {
        int fcur = fprev+sum-n*A[n-i];
        res = max(fcur, res);
        fprev = fcur;
    }
    return res;
}

int main() {
    int a[] = {4,3,2,6};
    vector<int> A = arrayToVector(a);
    cout<<maxRotateFunction(A)<<endl;
    return 0;
}
