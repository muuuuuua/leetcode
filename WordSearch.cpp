/**
 * 79. Word Search
 */
#include "inc/common.h"

int dir[][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool exist(vector<vector<char> >& board, int x, int y, string word, int index, vector<vector<bool> > &map) {
    if(board[x][y] != word[index])
        return false;
    if(index == word.size()-1)
        return true;
    for(int k = 0;k < 4;k++) {
        int nextx = x+dir[k][0];
        int nexty = y+dir[k][1];
        if(nextx >= 0 && nextx < board.size() && nexty >= 0 && nexty < board[0].size() && !map[nextx][nexty]) {
            map[nextx][nexty] = true;
            if(exist(board, nextx, nexty, word, index+1, map))
                return true;
            map[nextx][nexty] = false;
        }
    }
    return false;
}

bool exist(vector<vector<char> >& board, string word) {
    if(board.size() == 0 || board[0].size() == 0)
        return false;
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool> > map(m, vector<bool>(n, false));
    for(int i = 0;i < board.size();i++) {
        for(int j = 0;j < board[i].size();j++) {
            map[i][j] = true;
            if(exist(board, i, j, word, 0, map)) {
                return true;
            }
            map[i][j] = false;
        }
    }
    return false;
}

int main() {
    char a[][4] = {{'A','B','C','E'},
                  {'S','F','C','S'},
                  {'A','D','E','E'}};
    vector<vector<char> > board;           
    for(int i = 0;i < 3;i++) {
        vector<char> t = arrayToVector(a[i]);
        board.push_back(t);
    }
    cout<<exist(board, "ABCB")<<endl;
    return 0;
}
