/**
 * 234. Palindrome Linked List
 */
#include <iostream>

using namespace std;

bool isPalindrome(ListNode *head) {
    if(head == NULL)
        return true;
    ListNode *slow = head, *fast = head;
    ListNode *pre = NULL;
    int count = 0;
    while(fast != NULL) {
        fast = fast->next;
        count++;
        if(fast != NULL) {
            fast = fast->next;
            count++;
        }
        ListNode *temp = slow->next;
        slow->next = pre;
        pre = slow;
        slow = temp;
    }
    if(count % 2 != 0)
        pre = pre->next;
    while(pre != NULL) {
        if(pre->val != slow->val) return false;
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}
