class PeekingIterator : public Iterator {
private:
    int next_val;
    bool has_next;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize the cache with the first element if available
        has_next = Iterator::hasNext();
        if (has_next) {
            next_val = Iterator::next();
        }
    }
    
    // Returns the next element in the iteration without moving the pointer.
    int peek() {
        return next_val;
    }
    
    // Returns the next element in the array and moves the pointer to the next element.
    int next() {
        int current_val = next_val;
        
        // Advance and cache the following element
        has_next = Iterator::hasNext();
        if (has_next) {
            next_val = Iterator::next();
        }
        
        return current_val;
    }
    
    // Returns true if there are still elements in the array.
    bool hasNext() const {
        return has_next;
    }
};