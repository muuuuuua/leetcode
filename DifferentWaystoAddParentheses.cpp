/**
 * 241. Different Ways to Add Parentheses
 */
#include "inc/common.h"

unordered_map<string, vector<int> > memo;

vector<int> diffWaysToCompute(string input) {
    vector<int> res;
    if(memo.find(input) != memo.end()) 
        return memo[input];
    for(int i = 0;i < input.size();i++) {
        char c = input[i];
        if(c == '+' || c == '-' || c == '*') {
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1, input.size()-i-1));
            for(int j = 0;j < left.size();j++) {
                for(int k = 0;k < right.size();k++) {
                    if(c == '+')
                        res.push_back(left[j]+right[k]);
                    else if(c == '-') 
                        res.push_back(left[j]-right[k]);
                    else
                        res.push_back(left[j]*right[k]);
                }
            }
        }
    }
    if(res.size() == 0) {
        int t = 0;
        for(int i = 0;i < input.size();i++) {
            t = t*10 + input[i]-'0';
        }
        res.push_back(t);
    }
    memo[input] = res;
    return res;
}

int main() {
    vector<int> r = diffWaysToCompute("2-1-1");
    printVector(r);
    return 0;
}
