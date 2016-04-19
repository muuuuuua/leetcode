/**
 * 295. Find Median from Data Stream
 */
#include "inc/common.h"

struct DoubleListNode {
    int val;
    DoubleListNode *next, *prev;
    DoubleListNode(int x):val(x),next(NULL),prev(NULL) {}
};

class MedianFinder {
private:
    DoubleListNode *head;
    DoubleListNode *m1, *m2;
public:
    MedianFinder() {
        head = new DoubleListNode(0);
        m1 = NULL;
        m2 = NULL;
    }
    // Adds a number into the data structure.
    void addNum(int num) {
        DoubleListNode *cur = head;
        DoubleListNode *n = new DoubleListNode(num);
        while(cur != NULL) {
            if(cur->next == NULL || num <= cur->next->val) {
                n->next = cur->next;
                if(cur->next != NULL)
                    cur->next->prev = n;
                cur->next = n;
                n->prev = cur;
                break;
            }
            cur = cur->next;
        }
        if(m1 == NULL) {
            m1 = n;
            m2 = n;
        }
        else if(m1 == m2) {
            if(num <= m1->val)
                m1 = m1->prev;
            else
                m2 = m2->next;
        }
        else {
            if(num <= m1->val)
                m2 = m2->prev;
            else if(num > m2->val) {
                m1 = m1->next;
            }
            else {
                m1 = n;
                m2 = n;
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        return ((double)m1->val+(double)m2->val)/2;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(6);
    cout<<mf.findMedian()<<endl;
    mf.addNum(10);
    cout<<mf.findMedian()<<endl;
    mf.addNum(2);
    cout<<mf.findMedian()<<endl;
    mf.addNum(6);
    cout<<mf.findMedian()<<endl;
    mf.addNum(5);
    cout<<mf.findMedian()<<endl;
    return 0;
}
