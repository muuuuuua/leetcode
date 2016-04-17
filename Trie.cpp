/**
 * 208. Implement Trie (Prefix Tree)
 */
#include "inc/common.h"

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *son[27];
    TrieNode() {
        for(int i = 0;i < 27;i++) {
            son[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0;i < word.size();i++) {
            if(cur->son[word[i]-'a'] == NULL) {
                cur->son[word[i]-'a'] = new TrieNode();
            }
            cur = cur->son[word[i]-'a'];
        }
        cur->son[26] = new TrieNode();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for(int i = 0;i < word.size();i++) {
            if(cur->son[word[i]-'a'] == NULL) {
                return false;
            }
            cur = cur->son[word[i]-'a'];
        }
        return cur->son[26]!=NULL;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for(int i = 0;i < prefix.size();i++) {
            if(cur->son[prefix[i]-'a'] == NULL) {
                return false;
            }
            cur = cur->son[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("aaaa");
    trie.insert("aaab");
    trie.insert("aaaz");
    trie.insert("aaa");
    trie.insert("aab");
    trie.insert("aaz");
    cout<<trie.search("aaaa")<<endl;
    cout<<trie.search("aaaaa")<<endl;
    cout<<trie.search("aaa")<<endl;
    cout<<trie.search("a")<<endl;
    return 0;
}

