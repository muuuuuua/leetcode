/**
 * 116. Populating Next Right Pointers in Each Node
 */

void connect(TreeLinkNode *root) {
    if(root == NULL)
        return;
    TreeLinkNode *cur, *pre = root;
    while(pre->left) {
        cur = pre;
        while(cur) {
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}
