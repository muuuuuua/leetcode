/**
 * 337. House Robber III
 */
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max(int a, int b) {
    return a>b?a:b;
}

void calculateVal(TreeNode *root, unordered_map<TreeNode*, int> &robbed, unordered_map<TreeNode*, int> &notrobbed) {
    if(root == NULL)
        return;
    if(robbed.find(root->left) == robbed.end()) {
        calculateVal(root->left, robbed, notrobbed);
    }
    if(robbed.find(root->right) == robbed.end()) {
        calculateVal(root->right, robbed, notrobbed);
    }
    robbed[root] = notrobbed[root->left]+notrobbed[root->right]+root->val;
    notrobbed[root] = max(robbed[root->left], notrobbed[root->left])+max(robbed[root->right], notrobbed[root->right]);
}

int rob(TreeNode *root) {
    if(root == NULL)
        return 0;
    unordered_map<TreeNode*, int> robbed, notrobbed;
    robbed[NULL] = 0;
    notrobbed[NULL] = 0;
    calculateVal(root, robbed, notrobbed);
    return max(robbed[root], notrobbed[root]);
}

int main() {
    return 0;
}
