/**
 * 284. Peeking Iterator
 */
#include "inc/common.h"

class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class PeekingIterator : public Iterator {
    int nextVal;
    bool hasNextVal;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    if(Iterator::hasNext()) {
            nextVal = Iterator::next();
            hasNextVal = true;
        }
        else {
            hasNextVal = false;
        }
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(hasNextVal)
            return nextVal;
        else
            return -1;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    int t = nextVal;
        if(Iterator::hasNext())
            nextVal = Iterator::next();
        else
            hasNextVal = false;
        return t;
	}

	bool hasNext() const {
	    return hasNextVal || Iterator::hasNext();
	}
};
