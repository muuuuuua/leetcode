/**
 * 130. Surrounded Regions
 */
#include "inc/common.h"

void dfs(int x, int y, vector<vector<char> >& board) {
    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
        return;
    if(board[x][y] != 'O')
        return;
    board[x][y] = '*';
    if(x+2 < board.size())
        dfs(x+1, y, board);
    if(x-2 >= 0)
        dfs(x-1, y, board);
    if(y+2 < board[0].size())
        dfs(x, y+1, board);
    if(y-2 >= 0)
        dfs(x, y-1, board);
}

void solve(vector<vector<char> >& board) {
    if(board.size() == 0 || board[0].size() == 0)
        return;
    int n = board.size();
    int m = board[0].size();
    for(int j = 0;j < m;j++) {
        if(board[0][j] == 'O')
            dfs(0, j, board);
        if(board[n-1][j] == 'O')
            dfs(n-1, j, board);
    }
    for(int i = 0;i < n;i++) {
        if(board[i][0] == 'O')
            dfs(i, 0, board);
        if(board[i][m-1] == 'O')
            dfs(i, m-1, board);
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            if(board[i][j] != '*')
                board[i][j] = 'X';
            else
                board[i][j] = 'O';
        }
    }
}

int main() {
    char a[][4] = {{'X','X','X','X'},
                {'X','O','O','X'},
                {'X','X','O','X'},
                {'X','O','X','X'}};
    vector<vector<char> > board;
    for(int i = 0;i < 4;i++) {
        board.push_back(arrayToVector(a[i]));
    }
    solve(board);
    print(board);
    return 0;
}
