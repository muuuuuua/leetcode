/**
 * 201. Bitwise AND of Numbers Range
 */
#include "inc/common.h"

int rangeBitwiseAnd(int m, int n) {
    int i = 0;
    while (m != n) {
        m = m >> 1;
        n = n >> 1;
        i++;
    }
    return m << i;
}

int main() {
    cout<<rangeBitwiseAnd(600000000, 2147483645)<<endl;
    return 0;
}
