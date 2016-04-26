/**
 * 76. Minimum Window Substring
 */
#include "inc/common.h"

string minWindow(string s, string t) {
    int map[256] = {0};
    for(int i = 0;i < t.size();i++) {
        map[t[i]]++;
    }
    int start = 0, end = 0, count = t.size();
    int minlen = s.size()+1, head = 0;
    while(end < s.size()) {
        map[s[end]]--;
        if(map[s[end]] >= 0)
            count--;
        while(count == 0) {
            if(end-start+1 < minlen) {
                minlen = end-start+1;
                head = start;
            }
            map[s[start]]++;
            if(map[s[start]] > 0) count++;
            start++;
        }
        end++;
    }
    if(minlen == s.size()+1)
        return "";
    else
        return s.substr(head, minlen);
}

int main() {
    cout<<minWindow("ADOBECODEBANC", "ABC")<<endl;
    return 0;
}
