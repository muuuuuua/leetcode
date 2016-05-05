/**
 * 140. Word Break II
 */
#include "inc/common.h"

unordered_set<string> find(string s, int l, int r, vector<bool>& dp, unordered_set<string>& wordDict) {
    unordered_set<string> res;
    if(wordDict.find(s.substr(l, r-l+1)) != wordDict.end())
        res.insert(s.substr(l, r-l+1));
    for(int i = l;i < r;i++) {
        if(dp[i] && wordDict.find(s.substr(i+1,r-i)) != wordDict.end()) {
            unordered_set<string> left = find(s, l, i, dp, wordDict);
            unordered_set<string> right = find(s, i+1, r, dp, wordDict);
            for(unordered_set<string>::iterator it1 = left.begin();it1 != left.end();it1++) {
                for(unordered_set<string>::iterator it2 = right.begin();it2 != right.end();it2++) {
                    string t = *it1+" "+*it2;
                    res.insert(t);
                }
            }
        }
    }
    return res;
}

vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    int n = s.size();
    vector<string> res;
    if(n == 0)
        return res;
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
    unordered_set<string> t = find(s, 0, s.size()-1, dp, wordDict);
    for(unordered_set<string>::iterator it = t.begin(); it != t.end();it++)
        res.push_back(*it);
    return res;
}

int main() {
    unordered_set<string> d;
    string a[] = {"cat", "cats", "and", "sand", "dog"};
    vector<string> b = arrayToVector(a);
    for(int i = 0;i < b.size();i++) {
        d.insert(b[i]);
    }
    vector<string> r = wordBreak("catsanddog", d);
    printVector(r);
    return 0;
}
