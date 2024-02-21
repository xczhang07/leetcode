class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        times = vector<int>(300, 0);
        hits = vector<int>(300, 0);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int idx = timestamp%300;
        if(times[idx] != timestamp)
        {
            times[idx] = timestamp;
            hits[idx] = 1;
        }
        else
            hits[idx]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int cnt = 0;
        for(int i = 0; i < 300; ++i)
        {
            if(timestamp-times[i] < 300)
                cnt += hits[i];
        }
        return cnt;
    }
    
    private:
        vector<int> times;
        vector<int> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
 
 Time Complexity:
 Hit: O(1)
 getHit: O(s)=> s is the interval given by the code challenge.

     
     
 class HitCounter {
public:
   /** Initialize your data structure here. */
    HitCounter() {
        this->hits.resize(300);
        this->lastPosition = 0;
        this->lastTime = 0;
        this->counter = 0;
    }

    /** 
    Record a hit.
    @param timestamp - The current timestamp (in seconds granularity). 
    */
    void hit(int timestamp) {
        update(timestamp);
        this->hits[this->lastPosition]++;
        this->counter++;
    }

    /** 
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). 
    */
    int getHits(int timestamp) {
        update(timestamp);
        return this->counter;
    }
    
    void update(int timestamp)
    {
        int gap = min(timestamp-this->lastTime, 300);
        for(int i = 0; i < gap; ++i)
        {
            this->lastPosition = (this->lastPosition+1) % 300;
            this->counter -= this->hits[this->lastPosition];
            this->hits[this->lastPosition] = 0;
        }
        this->lastTime = timestamp;
        return;
    }

    

private:
    vector<int> hits;
    int lastPosition;
    int lastTime;
    int counter;
};

// Binary Search Version.
/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

class HitCounter {
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        hits.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        int val = timestamp - 300;
        int l = 0, r = hits.size()-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(hits[m] <= val) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return hits.size()-l;
    }

    vector<int> hits;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
