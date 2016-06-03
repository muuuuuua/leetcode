/**
 * 301. Remove Invalid Parentheses
 */
#include "inc/common.h"

void find(string s, int step, int l, int r, int limitL, int limitR, int record, string temp, vector<string> &res, unordered_set<string> &set) {
    if(l > limitL || r > limitR) return;
    if(step == s.size()) {
        if(record == 0 && set.find(temp) == set.end()) {
            res.push_back(temp);
            set.insert(temp);
        }
        return;
    }
    if(s[step] != '(' && s[step] != ')') {
        temp += s[step];
        find(s, step+1, l, r, limitL, limitR, record, temp, res, set);
    }
    else if(s[step] == '(') {
        find(s, step+1, l+1, r, limitL, limitR, record, temp, res, set);
        record++;
        temp += '(';
        find(s, step+1, l, r, limitL, limitR, record, temp, res, set);
    }
    else {
        find(s, step+1, l, r+1, limitL, limitR, record, temp, res, set);
        if(record > 0) {
            record--;
            temp += ')';
            find(s, step+1, l, r, limitL, limitR, record, temp, res, set);
        }
    }

}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    if(s.size() == 0) {
        res.push_back("");
        return res;
    }
    int left = 0, minL = 0, minR = 0;
    for(int i = 0;i < s.size();i++) {
        if(s[i] == '(') left++;
        else if(s[i] == ')') {
            if(left > 0) left--;
            else minR++;
        }
    }
    minL = left;
    unordered_set<string> set;
    find(s, 0, 0, 0, minL, minR, 0, "", res, set);
    return res;
}

int main() {
    vector<string> r = removeInvalidParentheses("()())()");
    print(r);
    return 0;
}
