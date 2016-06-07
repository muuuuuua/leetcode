/**
 * 214. Shortest Palindrome
 */
#include "inc/common.h"

void calNext(vector<int> &next, string s) {
    next = vector<int>(s.size(), 0);
    next[0] = -1;
    int i = 0, k = -1;
    while(i < s.size()) {
        if(k == -1 || s[i] == s[k]) {
            i++;
            k++;
            next[i] = k;
        }
        else
            k = next[k];
    }
}

string shortestPalindrome(string s) {
    int n = s.size();
    if(n <= 1)
        return s;
    string r = s;
    reverse(r.begin(), r.end());
    string t = s + '#' + r;
    vector<int> next;
    calNext(next, t);
    int len = next.back()+1;
    string temp = s.substr(len, s.size()-len);
    reverse(temp.begin(), temp.end());
    return temp + s;
}

int main() {
    cout<<shortestPalindrome("aacecaaa")<<endl;
    return 0;
}
