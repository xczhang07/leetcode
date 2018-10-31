class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        else
        {
            l.erase(m[key]);
            l.push_front({key,m[key]->second});
            m[key] = l.begin();
            return m[key]->second;
        }
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end())
        {
            l.erase(m[key]);
            l.push_front({key, value});
            m[key] = l.begin();
        }
        else
        {
            if(l.size() < cap)
            {
                l.push_front({key, value});
                m[key] = l.begin();
            }
            else
            {
                m.erase(l.back().first);
                l.pop_back();
                l.push_front({key, value});
                m[key] = l.begin();
            }
        }
        return;
    }
private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
