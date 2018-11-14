class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.find(key) == m.end())
            m[key] = 1;
        else
            m[key]++;
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(m.find(key) == m.end())
            return;
        if(m[key] == 1)
        {
            --m[key];
            m.erase(key);
            return;
        }
        --m[key];
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(m.size() == 0)
            return "";
        int max_value = INT_MIN;
        string max_key;
        for(auto e : m)
        {
            if(e.second > max_value)
            {
                max_value = e.second;
                max_key = e.first;
            }
        }
        return max_key;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(m.size() == 0)
            return "";
        int min_value = INT_MAX;
        string min_key;
        for(auto e: m)
        {
            if(e.second < min_value)
            {
                min_value = e.second;
                min_key = e.first;
            }
        }
        return min_key;
    }
    
private:
    unordered_map<string, int> m;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
 
 /*
 the insert and remove is O(1) time complexity, the getMin and getMax is O(n), need to optimize it.
 */
