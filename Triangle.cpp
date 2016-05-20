/**
 * 120. Triangle
 */
#include "inc/common.h"

int min(int a, int b) {
    return a<b?a:b;
}

int minimumTotal(vector<vector<int> >& triangle) {
    if(triangle.size() == 0)
        return 0;
    if(triangle.size() == 1)
        return triangle[0][0];
    vector<int> prev, cur;
    prev = triangle[0];
    for(int i = 1;i < triangle.size();i++) {
        cur.push_back(triangle[i][0]+prev[0]);
        for(int j = 1;j < triangle[i].size()-1;j++) {
            int num = triangle[i][j];
            cur.push_back(min(prev[j], prev[j-1])+num);
        }
        cur.push_back(triangle[i][triangle[i].size()-1]+prev[triangle[i].size()-2]);
        prev = cur;
        cur = vector<int>();
    }
    int m = prev[0];
    for(int i = 1;i < prev.size();i++)
        m = m < prev[i]?m:prev[i];
    return m;
}

int main() {
    vector<vector<int> > triangle;
    int a[] = {1};
    triangle.push_back(arrayToVector(a));
    int b[] = {2,3};
    triangle.push_back(arrayToVector(b));
    cout<<minimumTotal(triangle)<<endl;
    return 0;
}
