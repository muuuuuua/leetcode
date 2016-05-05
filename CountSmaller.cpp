/**
 * 315. Count of Smaller Numbers After Self
 */
#include "inc/common.h"

struct Node {
    Node *left;
    Node *right;
    int val;
    int sum;
    Node(int x):val(x),sum(1),left(NULL),right(NULL) {}
};

int insert(int val, Node *root) {
    int count = 0;
    while(true) {
        if(val <= root->val) {
            root->sum++;
            if(root->left == NULL) {
                root->left = new Node(val);
                break;
            }
            else
                root = root->left;
        }
        else {
            count += root->sum;
            if(root->right == NULL) {
                root->right = new Node(val);
                break;
            }
            else
                root = root->right;
        }
    }
    return count;
}

vector<int> countSmaller(vector<int>& nums) {
    vector<int> res;
    if(nums.size() == 0)
        return res;
    Node *root = new Node(nums.back());
    res.insert(res.begin(), 0);
    for(int i = nums.size()-2;i >= 0;i--) {
        int t = insert(nums[i], root);
        res.insert(res.begin(), t);
    }
    return res;
}

int main() {
    int a[] = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    vector<int> b = arrayToVector(a);
    vector<int> c = countSmaller(b);
    printVector(c);
    return 0;
}
