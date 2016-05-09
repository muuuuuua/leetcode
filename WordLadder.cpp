/**
 * 127. Word Ladder
 */
#include "inc/common.h"

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    if(beginWord == endWord)
        return 2;
    queue<string> q1, q2;
    q1.push(beginWord);
    wordList.erase(beginWord);
    int len = 2;
    while(!q1.empty()) {
        while(!q1.empty()) {
            string s = q1.front();
            q1.pop();
            for(int i = 0;i < s.size();i++) {
                string temp = s;
                for(char c = 'a';c <= 'z';c++) {
                    temp[i] = c;
                    if(temp == endWord)
                        return len;
                    if(temp == s || wordList.find(temp) == wordList.end())
                        continue;
                    q2.push(temp);
                    wordList.erase(temp);
                }
            }
        }
        q1.swap(q2);
        len++;
    }
    return 0;
}

int main() {
    string a[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> w = arrayToSet(a);
    cout<<ladderLength("hit", "cog", w)<<endl;
    return 0;
}
