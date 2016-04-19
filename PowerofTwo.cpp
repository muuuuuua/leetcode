/**
 * 231. Power of Two
 */
#include "inc/common.h"

bool isPowerOfTwo(int n) {
    return n > 0 && (n&(n-1)) == 0;
}

int main() {
    cout<<isPowerOfTwo(4)<<endl;
    return 0;
}
