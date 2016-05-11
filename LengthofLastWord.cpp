/**
 * 58. Length of Last Word
 */
#include "inc/common.h"

int lengthOfLastWord(string s) {
    int len = 0;
    int prev = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] != ' ')
            len++;
        else {
            prev = len == 0?prev:len;
            len = 0;
        }
    }
    return len == 0?prev:len;
}

int main() {
    cout<<lengthOfLastWord("hello world")<<endl;
    return 0;
}
