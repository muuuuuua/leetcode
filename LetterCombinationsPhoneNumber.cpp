/**
 * 17. Letter Combinations of a Phone Number
 */
#include "inc/common.h"

void find(string digits, int step, string temp, vector<string>& res) {
    if(step == digits.size()) {
        res.push_back(temp);
        return;
    }
    string charMap[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string a = charMap[digits[step]-'0'];
    for(int i = 0;i < a.size();i++) {
        find(digits, step+1, temp+a[i], res);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    int len = digits.size();
    if(len == 0) return res;
    for(int i = 0;i < len;i++) {
        if(digits[i] == '1' || digits[i] == '0')
            return res;
    }

    find(digits, 0, "", res);
    return res;
}

int main() {
    vector<string> b = letterCombinations("23");
    print(b);
    return 0;
}
