/**
 * 117. Populating Next Right Pointers in Each Node II
 */

void connect(TreeLinkNode *root) {
    if(root == NULL)
        return;
    TreeLinkNode *cur = root, *nexthead = NULL, *nc = NULL;
    while(cur) {
        nexthead = new TreeLinkNode(0);
        nc = nexthead;
        while(cur) {
            if(cur->left) {
                nc->next = cur->left;
                nc = nc->next;
            }
            if(cur->right) {
                nc->next = cur->right;
                nc = nc->next;
            }
            cur = cur->next;
        }
        cur = nexthead->next;
        delete nexthead;
    }
}
