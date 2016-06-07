/**
 * 336. Palindrome Pairs
 */
#include "inc/common.h"

bool isPalin(string s) {
    int n = s.size();
    for(int i = 0;i < n/2;i++) {
        if(s[i] != s[n-i-1])
            return false;
    }
    return true;
}

vector<vector<int> > palindromePairs(vector<string>& words) {
    vector<vector<int> > res;
    int n = words.size();
    if(n <= 1) return res;
    unordered_map<string, int> map;
    for(int i = 0;i < n;i++)
        map[words[i]] = i;
    for(int i = 0;i < n;i++) {
        string s = words[i];
        int left = 0, right = 0;
        while(right < s.size()) {
            string r = s.substr(0, right);
            reverse(r.begin(), r.end());
            if(isPalin(s.substr(right, s.size()-right)) && map.count(r) && i != map[r]) {
                res.push_back({i, map[r]});
            }
            right++;
        }
        while(left <= s.size()) {
            string r = s.substr(left, s.size()-left);
            reverse(r.begin(), r.end());
            if(isPalin(s.substr(0, left)) && map.count(r) && i != map[r]) {
                res.push_back({map[r], i});
            }
            left++;
        }

    }
    return res;
}

int main() {

}

