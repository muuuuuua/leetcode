/**
 * 394. Decode String
 */
#include "inc/common.h"

string decode(string s, int &index) {
    string res = "";
    int times = 0;
    while(index < s.size()) {
        if(s[index] >= '0' && s[index] <= '9') {
            times = times*10+s[index]-'0';
            index++;
        }
        else if(s[index] == '[') {
            index++;
            string t = decode(s, index);
            for(int i = 0;i < times;i++) 
                res += t;
            times = 0;
        }
        else if(s[index] == ']') {
            index++;
            return res;
        }
        else {
            res += s[index];
            index++;
        }
    }
    return res;
}

string decodeString(string s) {
    int index = 0;
    s = "1["+s+"]";
    return decode(s, index);
}

int main() {
    cout<<decodeString("3[a3[dd]]2[bc]")<<endl;
    return 0;
}
