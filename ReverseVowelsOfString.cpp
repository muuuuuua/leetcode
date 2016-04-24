/**
 * 345. Reverse Vowels of a String
 */
#include "inc/common.h"

string reverseVowels(string s) {
    string res = "";
    stack<char> vowel;
    for(int i = 0;i < s.size();i++) {
        switch(s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                vowel.push(s[i]);
                break;
        }
    }
    for(int i = 0;i < s.size();i++) {
        switch(s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                res += vowel.top();
                vowel.pop();
                break;
            default:
                res += s[i];
                break;
        }
    }
    return res;
}

int main() {
    cout<<reverseVowels("leetcode")<<endl;
    return 0;
}
