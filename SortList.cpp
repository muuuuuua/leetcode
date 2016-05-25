/**
 * 148. Sort List
 */
#include "inc/common.h"

ListNode *sortList(ListNode *head) {
    if(!head || !head->next) return head;
    ListNode *slow = head, *fast = head, *prev = head;
    while(fast) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
        if(fast) fast = fast->next;
    }
    prev->next = NULL;
    ListNode *h1 = sortList(head);
    ListNode *h2 = sortList(slow);
    ListNode *h, *c1 = h1, *c2 = h2;
    if(h1->val < h2->val) {
        c1 = c1->next;
        h = h1;
    }
    else {
        c2 = c2->next;
        h = h2;
    }
    ListNode *c = h;
    while(c1 && c2) {
        if(c1->val < c2->val) {
            c->next = c1;
            c1 = c1->next;
            c = c->next;
        }
        else {
            c->next = c2;
            c2 = c2->next;
            c = c->next;
        }
    }
    while(c1) {
        c->next = c1;
        c1 = c1->next;
        c = c->next;
    }
    while(c2) {
        c->next = c2;
        c2 = c2->next;
        c = c->next;
    }
    return h;
}

int main() {
    int a[] = {2,2,3,55,1,2};
    ListNode *head = makeList(a);
    head = sortList(head);
    print(head);
    return 0;
}

