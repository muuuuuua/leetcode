/**
 * 382. Linked List Random Node
 */

#include "inc/common.h"

class Solution {
private:
    int size;
    ListNode *h;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand(time(NULL));
        size = 0;
        ListNode *p = head;
        h = head;
        while(p != NULL) {
            size++;
            p = p->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int index = rand()%size;
        ListNode *p = h;
        while(index > 0) {
            index--;
            p = p->next;
        }
        return p->val;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution obj = Solution(head);
    cout<<obj.getRandom()<<endl;
    return 0;
}