/**
 * 405. Convert a Number to Hexadecimal
 */
#include "inc/common.h"

char convertBinary(int a[], int i) {
    int sum = a[i]*8+a[i+1]*4+a[i+2]*2+a[i+3];
    if(sum < 10) return sum+'0';
    else return sum-10+'a';
}

string toHex(int num) {
    string res = "";
    int temp[32] = {0};
    if(num == 0) return "0";
    if(num < 0) {
        temp[0] = 1;
        num += (1<<31);
    }
    int index = 31;
    while(num != 0) {
        temp[index] = num % 2;
        num /= 2;
        index--;
    }
    bool flag = false;
    for(int i = 0;i < 32;i+=4) {
        char c = convertBinary(temp, i);
        if(c != '0') flag = true;
        if(flag) res += c;
    }
    return res;
}

int main() {
    cout<<toHex(26)<<endl;
    return 0;
}
