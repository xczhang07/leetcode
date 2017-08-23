class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0)
            return 0;
        if(timeSeries.size() == 1)
            return duration;
        int ret  = 0;
        for(int i = 1; i < timeSeries.size(); ++i)
        {
            if(timeSeries[i]-timeSeries[i-1] >= duration)
                ret += duration;
            else
                ret += (timeSeries[i]-timeSeries[i-1]);
        }
        ret += duration;
        return ret;
    }
};


Conclustion:
a middle level algorithm issue, IMO, it is an easy level issue. 
time complexity: O(n)
space complexity: O(1)
