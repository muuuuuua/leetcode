/**
 * 146. LRU Cache
 */
#include "inc/common.h"

struct DualList {
    int val;
    int key;
    DualList *next;
    DualList *prev;
    DualList(int k, int v):key(k),val(v),next(NULL),prev(NULL) {}
};

class LRUCache{
private:
    int capa;
    int size;
    DualList *head, *tail;
    unordered_map<int, DualList*> map;
public:
    LRUCache(int capacity) {
        capa = capacity;
        size = 0;
        head = new DualList(0, 0);
        tail = new DualList(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()) {
            return -1;
        }
        else {
            DualList *v = map[key];
            int val = v->val;
            DualList *p = v->prev;
            DualList *n = v->next;
            p->next = n;
            n->prev = p;
            head->next->prev = v;
            v->next = head->next;
            v->prev = head;
            head->next = v;
            return val;
        }
    }
    
    void set(int key, int value) {
        if(map.find(key) != map.end()) {
            DualList *p = map[key];
            p->prev->next = p->next;
            p->next->prev = p->prev;
            head->next->prev = p;
            p->next = head->next;
            p->prev = head;
            head->next = p;
            p->val = value;
        }
        else {
            DualList *v = new DualList(key, value);
            map[key] = v;
            head->next->prev = v;
            v->next = head->next;
            v->prev = head;
            head->next = v;
            if(size < capa) {
                size++;
            }
            else {
                DualList *todelete = tail->prev;
                todelete->prev->next = tail;
                tail->prev = todelete->prev;
                map.erase(todelete->key);
                delete todelete;
            }
        }
        
    }
};

int main() {
    LRUCache cache(2);
    cache.set(2,1);
    cache.set(3,2);
    print(cache.get(3));
    print(cache.get(2));
    cache.set(4,3);
    print(cache.get(2));
    print(cache.get(3));
    print(cache.get(4));

    return 0;
}
