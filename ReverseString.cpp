/**
 * 344. Reverse String
 */
#include "inc/common.h"

string reverseString(string s) {
    string r = "";
    for(int i = s.size()-1;i >= 0;i--) {
        r.push_back(s[i]);
    }
    return r;
}

int main() {
    cout<<reverseString("hello")<<endl;
    return 0;
}
