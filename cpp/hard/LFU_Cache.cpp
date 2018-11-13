class LFUCache {
public:
    LFUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end())
            return -1;
        else
        {
            freq[m[key].second].erase(iter1[key]);
            ++m[key].second;
            freq[m[key].second].push_back(key);
            iter1[key] = --freq[m[key].second].end();
            if(freq[minFreq].size() == 0)
                ++minFreq;
            return m[key].first;
        }
    }
    
    void put(int key, int value) {
        if(this->cap <= 0)
            return;
        if(get(key) != -1)
        {
            m[key].first = value;
            return;
        }
        if(m.size() >= this->cap)
        {
            m.erase(freq[minFreq].front());
            iter1.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        m[key] = {value, 1};
        freq[1].push_back(key);
        iter1[key] = --freq[1].end();
        minFreq = 1;
    }

private:
    int cap;
    int minFreq;
    unordered_map<int,pair<int,int>> m; /* store the pair <key,value> appear times */
    unordered_map<int, list<int>> freq; /* store the the key of the table is frequence times, the list is the key value */
    unordered_map<int, list<int>::iterator> iter1;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
 
 /*
 a hard level design algorithm issue.
 */
