/**
 * 374. Guess Number Higher or Lower
 */
#include "inc/common.h"

int guess(int num) {
    int ans = 1702766719;
    if(num == ans) return 0;
    else if(num > ans) return -1;
    else return 1;
}

int guessNumber(int n) {
    int start = 1, end = n;
    while(start <= end) {
        int mid = (end-start)/2+start;
        int res = guess(mid);
        if(res == 0) return mid;
        else if(res > 0) start = mid+1;
        else end = mid-1;
    }
    return 0;
}

int main() {
    cout<<guessNumber(2126753390)<<endl;
    return 0;
}