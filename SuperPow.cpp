/**
 * 372. Super Pow
 */
#include "inc/common.h"

int divide(vector<int> &b, int a) {
    int rest = 0, index = 0;
    vector<int> temp;
    while(index <= b.size()) {
        if(temp.size() != 0 || rest/a != 0)
        temp.push_back(rest/a);
        rest %= a;
        if(index < b.size()) {
            rest = rest*10+b[index];
        }
        else
            break;
        index++;
    }
    if(temp.size() != 0)
        b = temp;
    else {
        b = vector<int>(1,0);
    }
    return rest;
}

bool equal(vector<int> &b, int a) {
    int sum = 0;
    for(int i = 0;i < b.size();i++)
        sum = sum*10+b[i];
    return sum == a;
}

int superPow(int a, vector<int>& b) {
    a %= 1337;
    if(equal(b, 0)) 
        return 1;
    int unit = 8;
    int mod = divide(b, unit);
    int t = superPow(a, b) % 1337;
    
    while(unit > 1) {
        t = (t*t) % 1337;
        unit /= 2;
    }
    while(mod > 0) {
        t = (t*a) % 1337;
        mod--;
    }
    return t;
}

int main() {
    int b[] = {1,0};
    vector<int> vb = arrayToVector(b);
    cout<<superPow(2, vb)<<endl;
    return 0;
}