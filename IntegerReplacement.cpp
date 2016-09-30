/**
 * 397. Integer Replacement
 */
#include "inc/common.h"

unordered_map<int, int> hashtable;

int integerReplacement(int n) {
    if(n == 1) return 0;
    if(n == INT_MAX) return 32;
    if(hashtable.find(n) != hashtable.end()) return hashtable[n];
    if(n % 2 == 0) {
        int res = integerReplacement(n/2)+1;
        hashtable[n] = res;
        return res;
    }
    else {
        int res = min(integerReplacement(n+1), integerReplacement(n-1))+1;
        hashtable[n] = res;
        return res;
    }
}

int main() {
    cout<<integerReplacement(2147483647)<<endl;
    return 0;
}
