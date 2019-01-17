Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4

class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    /*get time complexity is O(1) */
    int get(int key) {
        /* move the current node which contains key to the head of the list */
        if(!m.count(key))
            return -1;
        auto pos = m[key];
        int val = pos->second;
        l.erase(pos);
        l.push_front(make_pair(key, val));
        m[key] = l.begin();
        return val;
    }
    
    /* put time complexity is O(1) */
    void put(int key, int value) {
        if(get(key) != -1)
        {
            m[key]->second = value;
            return;
        }
        /* if the size reach the capacity, remove the last(the least recently used one), and then push
        the new one into front */
        if(this->cap <= l.size())
        {
            int last = l.back().second;
            int key = l.back().first;
            l.pop_back();
            m.erase(key);
        }
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
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
