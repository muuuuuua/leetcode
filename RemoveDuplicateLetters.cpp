/**
 * 316. Remove Duplicate Letters
 */
#include "inc/common.h"

string removeDuplicateLetters(string s) {
    stack<char> temp;
    int count[26] = {0};
    bool added[26] = {false};
    for(int i = 0;i < s.size();i++) {
        count[s[i]-'a']++;
    }
    for(int i = 0;i < s.size();i++) {
        if(temp.empty()) {
            temp.push(s[i]);
            added[s[i]-'a'] = true;
        }
        else if(!added[s[i]-'a']) {
            while(!temp.empty() && temp.top() > s[i] && count[temp.top()-'a'] > 0) {
                added[temp.top()-'a'] = false;
                temp.pop();
            }
            temp.push(s[i]);
            added[s[i]-'a'] = true;
        }
        count[s[i]-'a']--;
    }
    string res = "";
    while(!temp.empty()) {
        res.insert(0, 1, temp.top());
        temp.pop();
    }
    return res;
}

int main() {
    string s = "rusrbofeggbbkyuyjsrzornpdguwzizqszpbicdquakqws";
    cout<<removeDuplicateLetters(s)<<endl;
    return 0;
}
