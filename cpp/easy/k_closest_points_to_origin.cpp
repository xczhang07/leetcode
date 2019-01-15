bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first*p1.first + p1.second*p1.second < p2.first*p2.first + p2.second*p2.second;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ret;
        if(points.size() == 0 || points[0].size() == 0)
            return ret;
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)>> pq(compare);
        for(int i = 0; i < points.size(); ++i)
        {
            if(pq.size() < K)
                pq.push(make_pair(points[i][0], points[i][1]));
            else
            {
                int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
                if(dis < pq.top().first*pq.top().first + pq.top().second*pq.top().second)
                {
                    pq.pop();
                    pq.push(make_pair(points[i][0], points[i][1]));
                }
            }
        }
        
        while(!pq.empty())
        {
            vector<int> tmp = {pq.top().first, pq.top().second};
            ret.push_back(tmp);
            pq.pop();
        }
        return ret;
    }
};


Time Complexity is: O(nlogk)
Space Complexity is: O(k)
