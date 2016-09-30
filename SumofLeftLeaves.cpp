/**
 * 404. Sum of Left Leaves
 */
#include "inc/common.h"

int sumOfLeftLeaves(TreeNode *root, bool left) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL && left)
        return root->val;
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int sumOfLeftLeaves(TreeNode *root) {
    return sumOfLeftLeaves(root, false);
}
