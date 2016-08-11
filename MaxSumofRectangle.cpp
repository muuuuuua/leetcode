/**
 * 363. Max Sum of Rectangle No Larger Than K
 */
#include "inc/common.h"

int maxSumSubmatrix(vector<vector<int> > & matrix, int k) {
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    if(n == 0) return 0;
    vector<vector<int> > sum(m, vector<int>(n, 0));
    for(int i = 0;i < m;i++) {
        sum[i][0] = matrix[i][0];
        for(int j = 1;j < n;j++) {
            sum[i][j] = sum[i][j-1]+matrix[i][j];
        }
    }
    int maxSum = INT_MIN;
    for(int col1 = 0;col1 < n;col1++) {
        for(int col2 = col1;col2 < n;col2++) {
            vector<int> temp;
            for(int i = 0;i < m;i++) {
                if(col1 == 0) temp.push_back(sum[i][col2]);
                else temp.push_back(sum[i][col2]-sum[i][col1-1]);
            }
            vector<int> rowSum(m, 0);
            rowSum[0] = temp[0];
            for(int i = 1;i < m;i++) {
                rowSum[i] = rowSum[i-1]+temp[i];
            }
            for(int i = 0;i < m;i++) {
                if(rowSum[i] > maxSum && rowSum[i] <= k)
                    maxSum = rowSum[i];
            }
            for(int row1 = 1;row1 < m;row1++) {
                for(int row2 = row1;row2 < m;row2++) {
                    int t = rowSum[row2]-rowSum[row1-1];
                    if(t <= k && t > maxSum)
                        maxSum = t;
                }
            }
        }
    }
    return maxSum;
}

int main() {
    vector<vector<int> > matrix;
    int a[] = {2,2,-1};
    matrix.push_back(arrayToVector(a));
    // int b[] = {0,-2,3};
    // matrix.push_back(arrayToVector(b));
    cout<<maxSumSubmatrix(matrix, 0)<<endl;
    return 0;
}