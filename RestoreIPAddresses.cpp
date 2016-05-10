/**
 * 93. Restore IP Addresses
 */
#include "inc/common.h"

int check(string s) {
    if(s.size() != 1 && s[0] == '0')
        return -1;
    int sum = 0;
    for(int i = 0;i < s.size();i++) {
        sum = sum*10 + s[i]-'0';
    }
    if(sum > 255)
        return -1;
    return sum;
}

void find(string s, int step, string temp, vector<string>& res) {
    if(step == 4) {
        if(s == "")
            res.push_back(temp);
        return;
    }
    for(int i = 1;i <= 3;i++) {
        if(i > s.size())
            return;
        string sub = s.substr(0, i);
        int num = check(sub);
        if(num != -1) {
            string next = temp + sub;
            if(step != 3)
                next += '.';
            find(s.substr(i, s.size()-i), step+1, next, res);
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if(s.size() < 4)
        return res;
    find(s, 0, "", res);
    return res;
}

int main() {
    vector<string> r = restoreIpAddresses("25525511135");
    print(r);
    return 0;
}
