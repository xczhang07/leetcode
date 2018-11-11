class RecentCounter {
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        if(q.empty())
        {
            q.push(t);
            return 1;
        }
        else
        {
            while(!q.empty() && (t-q.front() > 3000))
                q.pop();
            
            q.push(t);
            return q.size();
        }
    }
    
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
