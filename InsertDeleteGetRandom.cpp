/**
 * 380. Insert Delete GetRandom O(1)
 */
#include "inc/common.h"

class RandomizedSet {
private:
    unordered_map<int, int> map;
    vector<int> store;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) == map.end()) {
            store.push_back(val);
            map[val] = store.size()-1;
            return true;
        }
        else
            return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) == map.end())
            return false;
        else {
            int index = map[val];
            store[index] = store.back();
            map[store.back()] = index;
            store.pop_back();
            map.erase(val);
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
    RandomizedSet obj = RandomizedSet();
    obj.insert(0);
    obj.insert(1);
    obj.remove(0);
    obj.insert(2);
    obj.remove(1);
    cout<<obj.getRandom()<<endl;
    return 0;
}
