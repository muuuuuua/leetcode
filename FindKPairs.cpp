/**
 * 373. Find K Pairs with Smallest Sums
 */

#include "inc/common.h"

struct Node {
    int x, y, sum;
    Node(int a, int b, int c):x(a),y(b),sum(c) {}
    bool operator < (const Node &n) const {
        return sum > n.sum;
    }
};

vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int index1 = 0, index2 = 0;
    priority_queue<Node> q;
    vector<pair<int, int> > res;
    if(nums1.size() == 0 || nums2.size() == 0)
        return res;
    q.push(Node(index1, index2, nums1[index1]+nums2[index2]));
    for(int i = 0;i < k;i++) {
        if(q.empty())
            break;
        Node t = q.top();
        index1 = t.x;
        index2 = t.y;
        res.push_back(pair<int,int>(nums1[index1], nums2[index2]));
        q.pop();
        if(index1 == 0 && index2+1 < nums2.size())
            q.push(Node(index1, index2+1, nums1[index1]+nums2[index2+1]));
        if(index1+1 < nums1.size())
            q.push(Node(index1+1, index2, nums1[index1+1]+nums2[index2]));
    }
    return res;
}

int main() {
    int a[] = {1,2};
    int b[] = {3};
    vector<int> num1 = arrayToVector(a);
    vector<int> num2 = arrayToVector(b);
    vector<pair<int, int> > r = kSmallestPairs(num1, num2, 3);
    print(r);
    return 0;
}