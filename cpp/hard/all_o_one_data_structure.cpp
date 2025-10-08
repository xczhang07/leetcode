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
    AllOne() {
        
    }
    
    void inc(string key) {
        // if the key doesn't exist in the system.
        if(!keyMap.count(key)) {
            if(freqList.size() == 0 or freqList.back().first != 1) {
                auto addr = freqList.insert(freqList.end(), {1, {key}});
                keyMap[key] = addr;
            } else {
                freqList.back().second.insert(key);
                keyMap[key] = --freqList.end();
            }
            return;
        } else {
            auto addr = keyMap[key];
            auto prev = (--keyMap[key]); // the previous node of the list has higher frequency.
            if(prev->first != addr->first+1) {
                auto newAddr = freqList.insert(addr, {addr->first+1, {key}});
                keyMap[key] = newAddr;
            } else {
                prev->second.insert(key);
                keyMap[key] = prev;
            }
            addr->second.erase(key);
            if(addr->second.size() == 0) {
                freqList.erase(addr);
            }
            return;
        }
    }
    
    void dec(string key) {
        if(!keyMap.count(key)) {
            return;
        }
        auto addr = keyMap[key];
        if(addr->first == 1) {
            addr->second.erase(key);
            if(addr->second.size() == 0) {
                freqList.erase(addr);
            }
            keyMap.erase(key);
            return;
        }
        auto next = ++keyMap[key]; // the next one has lower frequency.
        if(next->first+1 != addr->first) {
            auto newAddr = freqList.insert(next, {addr->first-1, {key}});
            keyMap[key] = newAddr;
        } else {
            if(next == freqList.end()) { // fix a bug of the previous version.
                auto newAddr = freqList.insert(freqList.end(), {addr->first-1, {key}});
                keyMap[key] = newAddr;
            } else {
                next->second.insert(key);
                keyMap[key] = next;
            }
        }
        addr->second.erase(key);
        if(addr->second.size() == 0) {
            freqList.erase(addr);
        }
    }
    
    string getMaxKey() {
        if(freqList.size() == 0) {
            return "";
        }
        return *(freqList.front().second.begin());
    }
    
    string getMinKey() {
        if(freqList.size() == 0) {
            return "";
        }
        return *(freqList.back().second.begin());
    }
private:
    list<pair<int, unordered_set<string>>> freqList; // the list maps to frequency with its corresponding keys.
    unordered_map<string, list<pair<int, unordered_set<string>>>::iterator> keyMap; // for quick lookup.
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
