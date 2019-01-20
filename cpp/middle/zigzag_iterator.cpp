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


K array case:
class ZigzagIteratorK {
public:
    //TC: O(K) to push all iterators into the queue
    //SC: O(1), the queue takes only reference to the input variable v 
    //and does not create extra data structures
    ZigzagIteratorK(vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i].size() > 0)
                m_q.emplace(v[i].begin(), v[i].end());
        }   
    }
    
    int next() {
        //TC: O(1)
        //SC: O(1)
        vector<int>::iterator it1 = m_q.front().first;
        vector<int>::iterator it2 = m_q.front().second;
        m_q.pop();
        if (it1 + 1 != it2)
            m_q.emplace(it1 + 1, it2);
        return *it1;
    }
    
    bool hasNext() {
        //TC: O(1)
        //SC: O(1)
        return !m_q.empty();
    }
    
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> m_q;
};
