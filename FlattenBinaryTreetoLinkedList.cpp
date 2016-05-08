/**
 * 114. Flatten Binary Tree to Linked List
 */
#include "inc/common.h"

void flatten(TreeNode* root) {
    if(root == NULL)
        return;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    flatten(left);
    root->left = NULL;
    root->right = left;
    flatten(right);
    TreeNode *cur = root;
    while(cur->right != NULL)
        cur = cur->right;
    cur->right = right;
}
