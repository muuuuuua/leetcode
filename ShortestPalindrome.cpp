/**
 * 214. Shortest Palindrome
 */
#include "inc/common.h"

string shortestPalindrome(string s) {
    int n = s.size();
    if(n <= 1)
        return s;
    int i = 0, end = n-1;
    int j = end;
    while(i <= j) {
        if(s[i] == s[j]) {
            i++;
            j--;
        }
        else {
            i = 0;
            end--;
            j = end;
        }
    }
    string res = "";
    for(int i = n-1;i >= end;i--) {
        res += s[i];
    }
    res += s;

    return res;
}

int main() {
    cout<<shortestPalindrome("abdca")<<endl;
    return 0;
}
