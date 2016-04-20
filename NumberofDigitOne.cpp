/**
 * 233. Number of Digit One
 */
#include "inc/common.h"

int countDigitOne(int n) {
    if(n <= 0)
        return 0;
    long t = 10;
    int sum = 0;
    while(n / t != 0) {
        int a = n / t;
        int b = n % t;
        sum += a*t/10;
        if(b >= 2*t/10) {
            sum += t/10;
        }
        else if(b >= t/10) {
            sum += b%(t/10)+1;
        }
        t *= 10;
    }
    int b = n % t;
    if(b >= 2*t/10) {
        sum += t/10;
    }
    else if(b >= t/10) {
        sum += b%(t/10)+1;
    }
    return sum;
}

int main() {
    cout<<countDigitOne(1410065408)<<endl;
    return 0;
}
