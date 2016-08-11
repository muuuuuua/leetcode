/**
 * 381. Insert Delete GetRandom O(1) - Duplicates allowed
 */
#include "inc/common.h"

class RandomizedCollection {
private:
    unordered_map<int, priority_queue<int> > map;
    vector<int> store;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) == map.end()) {
            store.push_back(val);
            priority_queue<int> index;
            index.push(store.size()-1);
            map[val] = index;
            return true;
        }
        else {
            store.push_back(val);
            map[val].push(store.size()-1);
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end())
            return false;
        else {
            priority_queue<int> indexQ = map[val];
            int index = indexQ.top();
            indexQ.pop();
            store[index] = store.back();
            map[store.back()].pop();
            map[store.back()].push(index);
            store.pop_back();
            if(indexQ.empty())
                map.erase(val);
            else
                map[val] = indexQ;
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand()%store.size();
        return store[r];
    }
};

int main() {
    RandomizedCollection obj = RandomizedCollection();
    obj.insert(1);
    obj.insert(1);
    obj.insert(2);
    // obj.remove(1);
    cout<<obj.getRandom()<<endl;
    return 0;
}
