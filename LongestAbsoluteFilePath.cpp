/**
 * 388. Longest Absolute File Path
 */

#include "inc/common.h"

class MyFile {
public:
    bool isFile;
    string name;
    vector<MyFile *> children;
    int length;

    bool checkName(string s) {
        for(int i = 0;i < s.size()-1;i++) {
            if(s[i] == '.')
                return true;
        }
        return false;
    }
    MyFile(string x, int l) {
        name = x;
        isFile = checkName(x);
        length = l;
        if(!isFile) length++;
    }
};

int lengthLongestPath(string input) {
    MyFile *root = new MyFile("/", -1);
    MyFile *cur = root;
    int index = 0;
    string temp = "";
    input += '\n';
    int maxLen = 0;
    while(index < input.size()) {
        if(input[index] == '\n') {
            MyFile *t = new MyFile(temp, cur->length+temp.size());
            cur->children.push_back(t);
            if(t->isFile)
                maxLen = max(maxLen, t->length);
            cur = root;
            temp = "";
        }
        else if(input[index] == '\t') {
            cur = cur->children.back();
        }
        else {
            temp += input[index];
        }
        index++;
    }
    return maxLen;
}

int main() {
    int a = lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext");
    cout<<a<<endl;
    return 0;
}