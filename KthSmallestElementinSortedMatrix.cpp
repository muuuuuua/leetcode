/**
 * 378. Kth Smallest Element in a Sorted Matrix
 */

#include "inc/common.h"

struct Node {
    int val, i, j;
    Node():i(0),j(0),val(0) {}
    Node(int i, int j, int val) :i(i), j(j), val(val) {}
    bool operator < (const Node & x)const {
        return val > x.val;
    }
};

int kthSmallest(vector<vector<int> >& matrix, int k) {
    int n = matrix.size();
    if(n == 0) return 0;
    priority_queue<Node> q;
    q.push(Node(0, 0, matrix[0][0]));
    Node res;
    for(int i = 0;i < k;i++) {
        res = q.top();
        q.pop();
        if(res.i == 0 && res.j+1 < n)
            q.push(Node(0, res.j+1, matrix[0][res.j+1]));
        if(res.i+1 < n)
            q.push(Node(res.i+1, res.j, matrix[res.i+1][res.j]));
    }
    return res.val;
}

int main() {
    vector<vector<int> > matrix;
    int a[] = {1,5,9};
    matrix.push_back(arrayToVector(a));
    int b[] = {10,11,13};
    matrix.push_back(arrayToVector(b));
    int c[] = {12,13,15};
    matrix.push_back(arrayToVector(c));
    cout<<kthSmallest(matrix, 8)<<endl;
    return 0;
}