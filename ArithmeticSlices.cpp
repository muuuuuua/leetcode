/**
 * 413. Arithmetic Slices
 */
#include "inc/common.h"

int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    if(n < 3) return 0;

    int count = 0;
    for(int i = 0;i+3 <= n;i++) {
        int diff = A[i+1]-A[i];
        for(int j = i+2;j < n;j++) {
            if(A[j] - A[j-1] == diff)
                count++;
            else break;
        }
    }
    return count;
}

int main() {
    int a[] = {1,1,1,1,1};
    vector<int> A = arrayToVector(a);
    cout<<numberOfArithmeticSlices(A)<<endl;
    return 0;
}
