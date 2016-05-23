/**
 * 71. Simplify Path
 */
#include "inc/common.h"

struct DualList {
    DualList *next;
    DualList *parent;
    string dir;
    DualList(string x):dir(x),next(NULL),parent(NULL) {}
};

string simplifyPath(string path) {
    path += "/";
    DualList *root = new DualList("/");
    root->parent = root;
    DualList *cur = root;
    string temp = "";
    for(int i = 1;i < path.size();i++) {
        if(path[i] != '/')
            temp += path[i];
        else {
            if(temp == "." || temp == "") ;
            else if(temp == "..") {
                cur = cur->parent;
                if(cur->next) {
                    delete cur->next;
                    cur->next = NULL;
                }
            }
            else {
                if(cur->next)
                    delete cur->next;
                cur->next = new DualList(temp);
                cur->next->parent = cur;
                cur = cur->next;
            }
            temp = "";
        }
    }
    
    if(!root->next)
        return "/";
    string res = "";
    cur = root->next;
    while(cur) {
        res += "/";
        res += cur->dir;
        cur = cur->next;
    }
    return res;
}

int main() {
    cout<<simplifyPath("/abc/...")<<endl;
    return 0;
}
