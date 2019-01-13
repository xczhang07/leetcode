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
