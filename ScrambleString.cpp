/**
 * 87. Scramble String
 */
#include "inc/common.h"

bool isScramble(string s1, string s2) {
    if(s1 == s2) return true;
    int count[256] = {0};
    int len = s1.size();
    for(int i = 0;i < len;i++) {
        count[s1[i]]++;
        count[s2[i]]--;
    }
    for(int i = 0;i < 256;i++) {
        if(count[i] != 0) return false;
    }
    for(int i = 1;i < len;i++) {
        string sub11 = s1.substr(0,i), sub12 = s1.substr(i, len-i);
        string sub21 = s2.substr(0,i), sub22 = s2.substr(i, len-i);
        if(isScramble(sub11, sub21) && isScramble(sub12, sub22))
            return true;
        sub21 = s2.substr(0,len-i);
        sub22 = s2.substr(len-i, i);
        if(isScramble(sub11, sub22) && isScramble(sub12, sub21))
            return true;
    }
    return false;
}

int main() {
    cout<<isScramble("aaaaaaaaaab", "aaaaaaaaaaa")<<endl;
    return 0;
}
