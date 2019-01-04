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


class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(!m.count(key))
        {
            if(buckets.size() == 0 || buckets.back().first != 1)
            {
                auto newBucket = buckets.insert(buckets.end(), {1, {key}});
                m[key] = newBucket;
            }
            else
            {
                auto lastBucket = --buckets.end();
                lastBucket->second.insert(key);
                m[key] = lastBucket;
            }
            return;
        }
        else
        {
            auto currBucket = m[key];
            auto prevBucket = (--m[key]);
            if(prevBucket->first != currBucket->first+1)
            {
                auto newBucket = buckets.insert(currBucket, {currBucket->first+1, {key}});
                m[key] = newBucket;
                currBucket->second.erase(key);
                if(currBucket->second.empty())
                    buckets.erase(currBucket);
            }
            else
            {
                prevBucket->second.insert(key);
                m[key] = prevBucket;
                currBucket->second.erase(key);
                if(currBucket->second.empty())
                    buckets.erase(currBucket);
            }
            return;
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!m.count(key))
            return;
        auto currBucket = m[key];
        if(currBucket->first == 1)
        {
            currBucket->second.erase(key);
            if(currBucket->second.size()==0)
                buckets.erase(currBucket);
            m.erase(key);
            return;
        }
        
        auto nextBucket = ++m[key];
        if(nextBucket->first != currBucket->first-1)
        {
            auto newBucket = buckets.insert(nextBucket, {currBucket->first-1, {key}});
            m[key] = newBucket;
        }
        else
        {
            nextBucket->second.insert(key);
            m[key] = nextBucket;
        }
        currBucket->second.erase(key);
        if(currBucket->second.size() == 0)
            buckets.erase(currBucket);
        return;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(buckets.size() == 0)
            return "";
        else
            return *(buckets.front().second.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(buckets.size() == 0)
            return "";
        else
            return *(buckets.back().second.begin());
    }
    
private:
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> m;
    list<pair<int,unordered_set<string>>> buckets;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
