/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        pk_has_next = Iterator::hasNext();
        if(pk_has_next) {
            pk_next = Iterator::next();
        }
        
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return pk_next;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret = pk_next;
        pk_has_next = Iterator::hasNext();
        if(pk_has_next) {
            pk_next = Iterator::next();
        }
        return ret;
	}
	
	bool hasNext() const {
        return pk_has_next;
	}

private:
    int pk_next;
    bool pk_has_next;
   
};
