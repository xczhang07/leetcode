class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0; i < maxNumbers; ++i)
            phone_pool.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(phone_pool.empty())
            return -1;
        int num = *(phone_pool.begin());
        phone_pool.erase(phone_pool.begin());
        return num;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return phone_pool.count(number);
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        phone_pool.insert(number);
        return;
    }
    
private:
    unordered_set<int> phone_pool;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
 
 
 /*
 an middle level algorithm issue, we can use unordered_set to resolve this issue.
 */
