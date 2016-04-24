/**
 * 95. Unique Binary Search Trees
 */
#include "inc/common.h"

vector<TreeNode*> generate(int start, int end) {
    vector<TreeNode*> res;
    if(start > end) {
        res.push_back(NULL);
        return res;
    }
    for(int i = start;i <= end;i++) {
        vector<TreeNode *> left = generate(start, i-1);
        vector<TreeNode *> right = generate(i+1, end);
        for(int m = 0;m < left.size();m++) {
            for(int n = 0;n < right.size();n++) {
                TreeNode *root = new TreeNode(i);
                root->left = left[m];
                root->right = right[n];
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> res;
    if(n <= 0)
        return res;
    return generate(1, n);
}

int main() {
    return 0;
}
