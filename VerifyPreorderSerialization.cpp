/**
 * 331. Verify Preorder Serialization of a Binary Tree
 */
#include "inc/common.h"

bool isValidSerialization(string preorder) {
    if(preorder.size() == 0)
        return false;
    vector<string> token;
    int pos = -1;
    while((pos=preorder.find_first_of(",")) != -1) {
        token.push_back(preorder.substr(0, pos));
        preorder = preorder.substr(pos+1, preorder.size()-pos);
    }
    token.push_back(preorder);
    int count = 0;
    if(token[0] != "#") {
        count += 2;
    }
    for(int i = 1;i < token.size();i++) {
        if(token[i] == "#") {
            count--;
            if(count < 0)
                return false;
        }
        else {
            if(count <= 0)
                return false;
            count++;
        }
    }
    return count == 0;
}

int main() {
    cout<<isValidSerialization("9,#")<<endl;
    return 0;
}
