/**
 * 240. Search a 2D Matrix II
 */
#include "inc/common.h"

bool searchMatrix(vector<vector<int> >& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0)
        return false;
    int i = 0, j = matrix[0].size()-1;
    while(i < matrix.size() && j >= 0) {
        if(target == matrix[i][j])
            return true;
        else if(target > matrix[i][j])
            i++;
        else
            j--;
    }
    return false;
}
