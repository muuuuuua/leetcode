/**
 * 395. Longest Substring with At Least K Repeating Characters
 */
#include "inc/common.h"

int longestSubstring(string s, int k) {
    int start = 0, end = 0;
    vector<int> record(26, 0), remain(26, 0);
    for(int i = 0;i < s.size();i++) {
        remain[s[i]-'a']++;
    }
    while(end < s.size()) {
        
    }
}

int main() {
    cout<<longestSubstring("aaabb", 3)<<endl;
    return 0;
}
