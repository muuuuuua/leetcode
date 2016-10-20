/**
 * 419. Battleships in a Board
 */
#include "inc/common.h"

void dfs(int x, int y, vector<vector<char> >& board, vector<vector<bool> >& visit) {
    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
        return;
    if(visit[x][y] || board[x][y] != 'X') return;
    visit[x][y] = true;
    dfs(x+1, y, board, visit);
    dfs(x-1, y, board, visit);
    dfs(x, y+1, board, visit);
    dfs(x, y-1, board, visit);
}

int countBattleships(vector<vector<char> >& board) {
    int count = 0;
    int m = board.size();
    if(m == 0) return 0;
    int n = board[0].size();
    if(n == 0) return 0;
    vector<vector<bool> > visit(m, vector<bool>(n, false));
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            if(!visit[i][j] && board[i][j] == 'X') {
                dfs(i, j, board, visit);
                count++;
            }
        }
    }
    return count;
}

int main() {
    char a[][5] = {"X..X", "...X", "...X"};
    vector<vector<char> > board;
    for(int i = 0;i < 3;i++) {
        board.push_back(arrayToVector(a[i]));
    }
    print(board);
    cout<<countBattleships(board)<<endl;
    return 0;
}