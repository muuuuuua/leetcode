/**
 * 282. Expression Add Operators
 */
#include "inc/common.h"

void find(int index, long long cnum, long long num, long long res, string temp, string source, vector<string> &store) {
    cnum = 10*cnum+source[index]-'0';
    if(index == source.size()-1) {
        if(res + num*cnum == 0)
            store.push_back(temp+source[index]);
        return;
    }
    if(cnum != 0)
        find(index+1, cnum, num, res, temp+source[index], source, store);
    find(index+1, 0, 1, res + num*cnum, temp+source[index]+'+', source, store);
    find(index+1, 0, -1, res + num*cnum, temp+source[index]+'-', source, store);
    find(index+1, 0, num*cnum, res, temp+source[index]+'*', source, store);
}

vector<string> addOperators(string num, int target) {
    vector<string> res;
    if(num.size() == 0)
        return res;
    find(0, 0, 1, -(long long)target, "", num, res);
    return res;
}

int main() {
    vector<string> a = addOperators("105", 6);
    printVector(a);
    return 0;
}
