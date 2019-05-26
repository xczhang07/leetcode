class LRUCache {
public:
    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        if(!m.count(key))
            return -1;
        auto addr = m[key];
        int val = addr->second;
        l.erase(addr);
        l.push_front(make_pair(key, val));
        m[key] = l.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(get(key) != -1)
        {
            auto addr = m[key];
            addr->second = value;
            return;
        }
        if(m.size() == size)
        {
            auto last = l.back();
            int k = last.first;
            m.erase(k);
            l.pop_back();
        }
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        return;
    }
    
private:
    int size;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
