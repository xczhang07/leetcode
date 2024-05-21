第二轮VO 第二题 https://www.1point3acres.com/bbs/thread-1067696-1-1.html

//Meta
vector<int> getTopKSmallest(vector<vector<int>>& arrs, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> ret;
    for(int i = 0; i < arrs.size(); ++i) {
        pq.push({arrs[i][0], {0, i}});
    }
    while(ret.size() < k) {
        auto top = pq.top();
        pq.pop();
        int val = top.first;
        int idx = top.second.first;
        int arrIdx = top.second.second;
        ret.push_back(val);
        if(idx < arrs[arrIdx].size()-1) {
            pq.push({arrs[arrIdx][idx+1], {idx+1, arrIdx}});
        }
    }
    return ret;
}
