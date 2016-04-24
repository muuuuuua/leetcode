/**
 * 236. Lowest Common Ancestor of a Binary Tree
 */
#include "inc/common.h"

TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    if(root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if(left != NULL && right != NULL)
        return root;
    else if(left == NULL)
        return right;
    else
        return left;
}
