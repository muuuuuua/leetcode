/**
 * 211. Add and Search Word - Data structure design
 */
#include "inc/common.h"

class TrieNode {
public:
    TrieNode *son[27];
    TrieNode() {
        for(int i = 0;i < 27;i++) {
            son[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *cur = root;
        for(int i = 0;i < word.size();i++) {
            if(cur->son[word[i]-'a'] == NULL) {
                cur->son[word[i]-'a'] = new TrieNode();
            }

            cur = cur->son[word[i]-'a'];
        }
        if(cur->son[26] == NULL)
            cur->son[26] = new TrieNode();
    }
    
    bool search(string word, TrieNode *root) {
        TrieNode *cur = root;
        for(int i = 0;i < word.size();i++) {
            if(word[i] != '.') {
                if(cur->son[word[i]-'a'] == NULL) {
                    return false;
                }
                cur = cur->son[word[i]-'a'];
            }
            else {
                for(char c = 'a'; c <= 'z';c++) {
                    if(cur->son[c-'a'] == NULL) {
                        continue;
                    }
                    if(search(word.substr(i+1,word.size()-i-1), cur->son[c-'a'])) {
                        return true;
                    }
                }
                return false;
            }
        }
        return cur->son[26] != NULL;
    }
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root);
    }
private:
    TrieNode* root;
};


int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("a");
    wordDictionary.addWord("a");
    cout<<wordDictionary.search(".")<<endl;
    cout<<wordDictionary.search("a")<<endl;
    cout<<wordDictionary.search(".a")<<endl;
    cout<<wordDictionary.search("a.")<<endl;
    return 0;
}