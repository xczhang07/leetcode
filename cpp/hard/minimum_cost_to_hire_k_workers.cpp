struct worker
{
    double ratio;
    int quality;
    worker(double wage, int quality)
    {
        this->ratio = (double)(wage/quality);
        this->quality = quality;
    }
};

bool compare(worker w1, worker w2)
{
    return w1.ratio < w2.ratio;
}

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        if(quality.size() == 0 || wage.size() == 0) return 0;
        int n = quality.size();
        vector<worker> group;
        for(int i = 0; i < n; ++i)
        {
            worker tmp(wage[i], quality[i]);
            group.push_back(tmp);
        }
        
        /* sort the input worker according to their ratio */
        sort(group.begin(), group.end(), compare);
        priority_queue<int> q;
        int total_quality = 0;
        for(int i = 0; i < K; ++i)
        {
            total_quality += group[i].quality;
            q.push(group[i].quality);
        }
        
        double ret = total_quality * group[K-1].ratio;
        for(int i = K; i < n; ++i)
        {
            total_quality -= q.top();
            q.pop();
            q.push(group[i].quality);
            total_quality += group[i].quality;
            ret = min(ret, total_quality*group[i].ratio);
        }
        return ret;
        
    }
};
