/**
 * 22. Generate Parentheses
 */
#include "inc/common.h"

void generate(int n, int left, int right, string temp, vector<string> &res) {
    if(left == n) {
        while(right < n) {
            temp += ')';
            right++;
        }
        res.push_back(temp);
        return;
    }
    if(left == right) {
        generate(n, left+1, right, temp+'(', res);
    }
    else if(left > right) {
        generate(n, left+1, right, temp+'(', res);
        generate(n, left, right+1, temp+')', res);
    }
    else
        return;
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    generate(n, 0, 0, "", res);
    return res;
}

int main() {
    vector<string> r = generateParenthesis(3);
    print(r);
    return 0;
}
