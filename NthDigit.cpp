/**
 * 400. Nth Digit
 */
#include "inc/common.h"

int findNthDigit(int n) {
    long long t = 1, s = 9;
    while(n > s*t) {
        n -= (s*t);
        s *= 10;
        t += 1;
    }
    long long first = s/9, end = first*10, step = t;
    for(long long i = first;i < end;i++) {
        if(n <= step) {
            long long res = i;
            while(n < step) {
                res /= 10;
                n++;
            }
            return res % 10;
        }
        else
            n -= step;
    }
    return n;
}

int main() {
    cout<<findNthDigit(1000000000)<<endl;
    return 0;
}
