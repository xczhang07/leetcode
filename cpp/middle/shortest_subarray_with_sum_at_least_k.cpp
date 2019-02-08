class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        if(A.size() == 0)
            return 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int sum = 0;
        int ret = INT_MAX;
        for(int i = 0; i < A.size(); ++i)
        {
            sum += A[i];
            if(sum >= K)
                ret = min(ret, i+1);
            while(!pq.empty() && sum-pq.top().first >= K)
            {
                auto t = pq.top();
                ret = min(ret, i-t.second);
                pq.pop();
            }
            pq.push(make_pair(sum, i));
        }
        return ret == INT_MAX? -1: ret;x
    }
};
