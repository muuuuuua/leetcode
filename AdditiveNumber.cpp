/**
 * 306. Additive Number
 */
#include "inc/common.h"

string toString(long num) {
    string r = "";
    while(num != 0) {
        r.insert(r.begin(), num%10+'0');
        num /= 10;
    }
    return r;
}

long toInt(string s) {
    long num = 0;
    for(int i = 0;i < s.size();i++) {
        num = 10*num+s[i]-'0';
    }
    return num;
}

bool check(string num, long a, long b) {
    long c = a+b;
    string cstr = toString(c);
    if(cstr.size() > num.size())
        return false;
    for(int i = 0;i < cstr.size();i++) {
        if(cstr[i] != num[i])
            return false;
    }
    if(cstr.size() == num.size())
        return true;
    else
        return check(num.substr(cstr.size(), num.size()-cstr.size()), b, c);
}

bool isAdditiveNumber(string num) {
    int len = num.size();
    for(int i = 1;i <= len/2;i++) {
        for(int j = 1;j <= len/2;j++) {
            string a = num.substr(0, i);
            string b = num.substr(i, j);
            if((a.size() != 1 && a[0] == '0') || (b.size() != 1 && b[0] == '0'))
                continue;
            if(check(num.substr(i+j, len-i-j), toInt(a), toInt(b)))
                return true;
        }
    }
    return false;
}

int main() {
    cout<<isAdditiveNumber("1023")<<endl;
    return 0;
}
