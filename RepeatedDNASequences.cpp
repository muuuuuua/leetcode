/**
 * 187. Repeated DNA Sequences
 */
#include "inc/common.h"

vector<string> findRepeatedDnaSequences(string s) {
    unordered_set<string> set;
    unordered_set<string> res;
    vector<string> r;
    if(s.size() < 10)
        return r;
    for(int i = 0;i <= s.size()-10;i++) {
        string temp = s.substr(i, 10);
        if(set.find(temp) != set.end())
            res.insert(temp);
        else
            set.insert(temp);
    }
    
    for (unordered_set<string>::iterator i = res.begin(); i != res.end(); ++i) {
        r.push_back(*i);
    }
    return r;
}

int main() {
    vector<string> r = findRepeatedDnaSequences("AAAAAAAAAAAAA");
    printVector(r);
    return 0;
}
