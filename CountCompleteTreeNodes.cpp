/**
 * 222. Count Complete Tree Nodes
 */
#include "inc/common.h"

int countNodes(TreeNode *root) {
    if(root == NULL)
        return 0;
    int llvl = 0, rlvl = 0;
    TreeNode *l = root->left;
    TreeNode *r = root->right;
    while(l) {
        llvl++;
        l = l->left;
    }
    while(r) {
        rlvl++;
        r = r->right;
    }
    if(llvl == rlvl)
        return (1<<(llvl+1)) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}
