/**
 * 417. Pacific Atlantic Water Flow
 */
#include "inc/common.h"

void dfs(vector<vector<int> >& matrix, vector<vector<int> >& visit, int x, int y) {
    if(x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size())
        return;
    if(visit[x][y] != 0)
        return;
    visit[x][y] = 1;
    int dir[][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    for(int i = 0;i <= 3;i++) {
        int nx = x+dir[i][0];
        int ny = y+dir[i][1];
        if(nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size())
            continue;
        if(matrix[x][y] <= matrix[nx][ny]) {
            dfs(matrix, visit, nx, ny);
        }
    }
}

vector<pair<int, int> > pacificAtlantic(vector<vector<int> >& matrix) {
    vector<pair<int, int> > res;
    if(matrix.size() == 0 || matrix[0].size() == 0) 
        return res;
    int m = matrix.size(), n = matrix[0].size();

    vector<vector<int> > visit1(m, vector<int>(n, 0));
    vector<vector<int> > visit2(m, vector<int>(n, 0));

    for(int i = 0;i < m;i++) {
        dfs(matrix, visit1, i, 0);
        dfs(matrix, visit2, i, n-1);
    }
    for(int j = 0;j < n;j++) {
        dfs(matrix, visit1, 0, j);
        dfs(matrix, visit2, m-1, j);
    }
    for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {
            if(visit1[i][j] == 1 && visit2[i][j] == 1)
                res.push_back(pair<int, int>(i, j));
        }
    }
    return res;
}

int main() {
    vector<vector<int> > matrix;
    int a[][5] = {{1,2,2,3,5},
                  {3,2,3,4,4},
                  {2,4,5,3,1},
                  {6,7,1,4,5},
                  {5,1,1,2,4}};
    for(int i = 0;i < 5;i++)
        matrix.push_back(arrayToVector(a[i]));
    vector<pair<int, int> > b = pacificAtlantic(matrix);
    print(b);
    return 0;
}
