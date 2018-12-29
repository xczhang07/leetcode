class LFUCache {
public:
    LFUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        /* check whether or not the key is in the hash-map */
        if(!m.count(key))
            return -1;
        /*
        
        this is an update operation:
        1. first of all, we have to get the visit_times.
        2. we need to get the position of the key in the iterator.
        3. we need to remove the position in freq map(we need to update the freq map)
        4. increase the visit_times, and put the key into the new freq map.
        5. update the iter map.
        6. we need to check whehter or not the min_freq list is empty, if it is empty, increase it 1.
        
        */
        int visit_times = m[key].second;
        auto pos = iter[key];
        freq[visit_times].erase(pos);
        ++visit_times;
        m[key].second = visit_times;
        freq[visit_times].push_back(key);
        iter[key] = --freq[visit_times].end();
        if(freq[minFreq].size() == 0)
            ++minFreq;
        int val = m[key].first;
        return val;
    }
    
    void put(int key, int value) {
       /*
       
       This function implements the insert or update functionality for this system. it has the follow three cases:
       case 1, if find the key exist in the system, update it.
       case 2, if the capacity reach to the max size, remove the least frequently used item, then add the new one.
       case 3, if not, directly insert the element into the system and update the min frequency to the new insert item.
       
       */
        if(this->size <= 0)
            return;
        /* case 1: check whether or not the key exists in the system */
        if(get(key) != -1)
        {
            m[key].first = value;
            return;
        }
        /* case 2: check whehter or not the size reach to the maximum size 
            if it reaches the bottleneck size, just remove the minFreq one
        */
        if(m.size() >= this->size)
        {
            /* erase ops for the min_key in the three maps */
            int min_key = freq[minFreq].front();
            m.erase(min_key);
            freq[minFreq].pop_front();
            iter.erase(min_key);
        }
        
        /* case 3: we combine the insertion step for case2 and case3 together */
        m[key] = make_pair(value, 1);
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        minFreq = 1;
    }

private:
    unordered_map<int, pair<int,int>> m; /* the hash-map: {key: (value, visit_times)} */
    unordered_map<int, list<int>> freq; /* the hash-map: {visit_times: list of key which has the same visit times} */
    unordered_map<int, list<int>::iterator> iter; /* the hash-map: {key: the position in list} */
    int minFreq;
    int size;

};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
