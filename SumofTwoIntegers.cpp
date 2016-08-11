/**
 * 371. Sum of Two Integers
 */
#include "inc/common.h"

int getSum(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    while (b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main() {
    cout<<getSum(20,30)<<endl;
    return 0;
}