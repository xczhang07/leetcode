class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())
            q.push(make_pair(v1.begin(), v1.end()));
        if(!v2.empty())
            q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        auto f = q.front();
        auto i1 = f.first;
        auto i2 = f.second;
        q.pop();
        if(i1 + 1 != i2)
            q.push(make_pair(i1+1, i2));
        return *i1;
    }

    bool hasNext() {
        return !q.empty();
    }
    
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
 
 /*
 Time Complexity is: O(l1+l2)
 Space Complexity is: O(1)
 */
