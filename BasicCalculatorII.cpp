/**
 * 227. Basic Calculator II
 */
#include "inc/common.h"

int calculate(string s) {
    if(s.size() == 0)
        return 0;
    int i = 0;
    deque<int> store;
    deque<char> op;
    while(i < s.size()) {
        if(s[i] == ' ') {
            i++;
            continue;
        }
        if(s[i] >= '0' && s[i] <= '9') {
            int t = 0;
            while(s[i] >= '0' && s[i] <= '9') {
                t = t*10+s[i]-'0';
                i++;
            }
            if(!op.empty()) {
                char o = op.back();
                if(o == '*' || o == '/') {
                    op.pop_back();
                    int a = store.back();
                    store.pop_back();
                    int r;
                    if(o == '*')
                        r = a * t;
                    else
                        r = a / t;
                    store.push_back(r);
                }
                else
                    store.push_back(t);
            }
            else {
                store.push_back(t);
            }
        }
        else {
            op.push_back(s[i]);
            i++;
        }
    }
    while(!op.empty()) {
        char o = op.front();
        op.pop_front();
        int a = store.front();
        store.pop_front();
        int b = store.front();
        store.pop_front();
        if(o == '+')
            store.push_front(a+b);
        else
            store.push_front(a-b);
    }
    return store.front();

}

int main() {
    cout<<calculate(" 1-1+1")<<endl;
    return 0;
}
