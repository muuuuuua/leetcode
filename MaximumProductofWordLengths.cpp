/**
 * 318. Maximum Product of Word Lengths
 */
#include "inc/common.h"

int maxProduct(vector<string> &words) {
    if(words.size() < 2)
        return 0;
    vector<int> bitmap(words.size(), 0);
    for(int i = 0;i < words.size();i++) {
        int bit = 0;
        for(int j = 0;j < words[i].size();j++) {
            bit = bit|(1<<(words[i][j]-'a'));
        }
        bitmap[i] = bit;
    }
    int max = 0;
    for(int i = 0;i < words.size()-1;i++) {
        for(int j = i+1;j < words.size();j++) {
            if((bitmap[i] & bitmap[j]) == 0) {
                int t = words[i].size()*words[j].size();
                max = t>max?t:max;
            }
        }
    }
    return max;
}

int main() {
    string a[] = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    vector<string> b = arrayToVector(a, 6);
    cout<<maxProduct(b)<<endl;
    return 0;
}
