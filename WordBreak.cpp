/**
 * 139. Word Break
 */
#include "inc/common.h"

bool wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    if(n == 0)
        return true;
    vector<bool> dp(n, false);
    dp[0] = (wordDict.find(s.substr(0,1)) != wordDict.end());
    for(int i = 1;i < n;i++) {
        if(wordDict.find(s.substr(0, i+1)) != wordDict.end())
            dp[i] = true;
        else {
            for(int j = 0;j < i;j++) {
                if(dp[j] && wordDict.find(s.substr(j+1,i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
    }
    return dp[n-1];
}

int main() {
    unordered_set<string> d;
    string a[] = {"a", "abc", "b", "cd"};
    vector<string> b = arrayToVector(a);
    for(int i = 0;i < b.size();i++) {
        d.insert(b[i]);
    }
    cout<<wordBreak("abcd", d)<<endl;
    return 0;
}
