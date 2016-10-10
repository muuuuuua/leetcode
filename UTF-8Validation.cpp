/**
 * 393. UTF-8 Validation
 */
#include "inc/common.h"

/**
 *     range    |        UTF-8 octet sequence
 *   (decimal)  |              (binary)
 * -------------+-------------------------------------
 *     0-127    | 0xxxxxxx
 *   192-223    | 110xxxxx 10xxxxxx
 *   224-239    | 1110xxxx 10xxxxxx 10xxxxxx
 *   240-247    | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

 */
enum STATE {NORMAL, TAIL};
bool validUtf8(vector<int> &data) {
    STATE state = NORMAL;
    int tail = 0;
    for(int i = 0;i < data.size();i++) {
        int ch = data[i];
        if(ch < 0) return false;
        switch(state) {
            case NORMAL:
                if(ch <= 127) {}
                else if(ch >= 192 && ch <= 223) {
                    state = TAIL;
                    tail = 1;
                }
                else if(ch <= 239) {
                    state = TAIL;
                    tail = 2;
                }
                else if(ch <= 247) {
                    state = TAIL;
                    tail = 3;
                }
                else return false;
                break;
            case TAIL:
                if(ch >= 128 && ch <= 191)
                    tail--;
                else return false;
                if(tail == 0) state = NORMAL;
                break;
            default:
                return false;
        }
    }
    if(state != NORMAL) return false;
    return true;
}

int main() {
    int data[] = {235,140,4};
    vector<int> d = arrayToVector(data);
    cout<<validUtf8(d)<<endl;
    return 0;
}
