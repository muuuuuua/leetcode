/**
 * 415. Add Strings
 */
#include "inc/common.h"

string addStrings(string num1, string num2) {
    string res = "";
    int carry = 0;
    int i = num1.size()-1, j = num2.size()-1;
    while(i >= 0 && j >= 0) {
        int s = num1[i]-'0'+num2[j]-'0'+carry;
        carry = s/10;
        s %= 10;
        res.insert(res.begin(), s+'0');
        i--;
        j--;
    }
    while(i >= 0) {
        int s = num1[i]-'0'+carry;
        carry = s/10;
        s %= 10;
        res.insert(res.begin(), s+'0');
        i--;
    }
    while(j >= 0) {
        int s = num2[j]-'0'+carry;
        carry = s/10;
        s %= 10;
        res.insert(res.begin(), s+'0');
        j--;
    }
    if(carry == 1)
        res.insert(res.begin(), '1');
    return res;
}

int main() {
    cout<<addStrings("123", "456")<<endl;
    return 0;
}
