/**
 * 68. Text Justification
 */
#include "inc/common.h"

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    vector<string> temp;
    int len = 0;
    for(int i = 0;i < words.size();i++) {
        string w = words[i];
        if(temp.empty()) {
            temp.push_back(w);
            len = w.size();
            continue;
        }
        else if(len+1+w.size() <= maxWidth) {
            temp.push_back(w);
            len = len+1+w.size();
            continue;
        }
        string line = "";
        int wordCount = temp.size();
        int l = 0;
        for(int j = 0;j < wordCount;j++)
            l += temp[j].size();
        int space = maxWidth - l;
        if(wordCount == 1) {
            line += temp[0];
            for(int k = 0;k < space;k++)
                line += ' ';
        }
        else {
            int each = space / (wordCount-1);
            int addition = space % (wordCount-1);
            for(int k = 0;k < wordCount;k++) {
                line += temp[k];
                if(k != wordCount-1) {
                    for(int m = 0;m < each;m++)
                        line += ' ';
                    if(addition > 0) {
                        line += ' ';
                        addition--;
                    }
                }
            }
        }
        res.push_back(line);
        temp.clear();
        temp.push_back(w);
        len = w.size();
    }
    string lastline = "";
    for(int i = 0;i < temp.size();i++) {
        lastline += temp[i];
        if(i != temp.size()-1)
            lastline += ' ';
    }
    while(lastline.size() < maxWidth)
        lastline += ' ';
    res.push_back(lastline);
    return res;
}

int main() {
    string a[] = {"What","must","be","shall","be."};
    vector<string> b = arrayToVector(a);
    vector<string> r = fullJustify(b, 12);
    for(int i = 0;i < r.size();i++)
        cout<<r[i]<<endl;
    return 0;
}
