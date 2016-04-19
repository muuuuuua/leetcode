/**
 * 342. Power of Four
 */
#include "inc/common.h"

bool isPowerOfFour(int n) {
    return n > 0 && (n&(n-1)) == 0 && (n&0x55555555) == n;
}

int main() {
    cout<<isPowerOfFour(4)<<endl;
    return 0;
}
