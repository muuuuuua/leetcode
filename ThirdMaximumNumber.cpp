/**
 * 414. Third Maximum Number
 */
#include "inc/common.h"

class ThreeNums {
private:
    ListNode *head;
    int size;
public:
    ThreeNums():size(0) { head = new ListNode(0);}
    ~ThreeNums() {
        ListNode *cur = head;
        while(cur != NULL) {
            ListNode *t = cur->next;
            delete cur;
            cur = t;
        }
    }
    void insert(int x) {
        if(size == 0) {
            ListNode *n = new ListNode(x);
            head->next = n;
            size++;
        }
        else if(size < 3) {
            ListNode *cur = head->next;
            ListNode *pre = head;
            while(cur != NULL) {
                if(x == cur->val) return;
                if(x > cur->val) {
                    ListNode *n = new ListNode(x);
                    n->next = cur;
                    pre ->next = n;
                    break;
                }
                cur = cur->next;
                pre = pre->next;
            }
            if(cur == NULL) {
                ListNode *n = new ListNode(x);
                pre->next = n;
            }
            size++;
        }
        else {
            ListNode *cur = head->next;
            while(cur != NULL) {
                if(x == cur->val) return;
                if(x > cur->val) {
                    int temp = cur->val;
                    cur->val = x;
                    cur = cur->next;
                    while(cur != NULL) {
                        int t = cur->val;
                        cur->val = temp;
                        temp = t;
                        cur = cur->next;
                    }
                    break;
                }
                cur = cur->next;
            }
        }
    }
    int getMax() {
        if(size < 3) return head->next->val;
        ListNode *cur = head;
        while(cur->next != NULL) {
            cur = cur->next;
        }
        return cur->val;
    }
};

int thirdMax(vector<int>& nums) {
    ThreeNums t;
    for(int i = 0;i < nums.size();i++) {
        t.insert(nums[i]);
    }
    return t.getMax();
}

int main() {
    int a[] = {2, 1};
    vector<int> b = arrayToVector(a);
    cout<<thirdMax(b)<<endl;
    return 0;
}
