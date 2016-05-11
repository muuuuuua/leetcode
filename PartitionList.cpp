/**
 * 86. Partition List
 */
#include "inc/common.h"

ListNode* partition(ListNode* head, int x) {
    if(head == NULL)
        return head;
    ListNode *h1 = NULL, *t1 = NULL, *h2 = NULL, *t2 = NULL;
    ListNode *cur = head;
    while(cur != NULL) {
        if(cur->val < x) {
            if(h1 == NULL) {
                h1 = cur;
                t1 = cur;
            }
            else {
                t1->next = cur;
                t1 = cur;
            }
        }
        else {
            if(h2 == NULL) {
                h2 = cur;
                t2 = cur;
            }
            else {
                t2->next = cur;
                t2 = cur;
            }
        }
        cur = cur->next;
    }
    if(h1 == NULL)
        return h2;
    t1->next = h2;
    if(t2 != NULL)
        t2->next = NULL;
    return h1;
}

int main() {
    int a[] = {1,4,3,2,5,2};
    ListNode *l = makeList(a);
    ListNode *p = partition(l, 3);
    print(p);
    return 0;
}