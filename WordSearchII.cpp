/**
 * 212. Word Search II
 */
#include "inc/common.h"

struct TrieNode {
    TrieNode *son[26];
    bool isLeaf;
    TrieNode() {
        isLeaf = false;
        for(int i = 0;i < 26;i++)
            son[i] = NULL;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *cur = root;
        for(int i = 0;i < word.size();i++) {
            if(cur->son[word[i]-'a'] == NULL)
                cur->son[word[i]-'a'] = new TrieNode();
            cur = cur->son[word[i]-'a'];
        }
        cur->isLeaf = true;
    }
};

void find(vector<vector<char> >& board, int x, int y, string word, TrieNode *root, vector<string> &res) {
    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '#')
        return;
    char c = board[x][y];
    word += c;
    root = root->son[c-'a'];
    if(root == NULL)
        return;
    if(root->isLeaf) {
        res.push_back(word);
        root->isLeaf = false;
    }
    board[x][y] = '#';
    find(board, x+1, y, word, root, res);
    find(board, x, y+1, word, root, res);
    find(board, x-1, y, word, root, res);
    find(board, x, y-1, word, root, res);
    board[x][y] = c;
}

vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
    vector<string> res;
    if(board.size() == 0 || board[0].size() == 0)
        return res;
    Trie *root = new Trie();
    for(int i = 0;i < words.size();i++) {
        root->insert(words[i]);
    }
    for(int i = 0;i < board.size();i++) {
        for(int j = 0;j < board[i].size();j++) {
            find(board, i, j, "", root->root, res);
        }
    }
    return res;
}

int main() {
    char a[][4] = {{'o','a','a','n'},
                  {'e','t','a','e'},
                  {'i','h','k','r'},
                  {'i','f','l','v'}};
    vector<vector<char> > board;           
    for(int i = 0;i < 4;i++) {
        vector<char> t = arrayToVector(a[i]);
        board.push_back(t);
    }
    string b[] = {"oath","pea","eat","rain"};
    vector<string> words = arrayToVector(b);
    vector<string> r = findWords(board, words);
    printVector(r);
    return 0;
}
