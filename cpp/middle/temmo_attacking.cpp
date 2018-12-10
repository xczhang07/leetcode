class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size()==0)
            return 0;
        int ret = duration;
        int end = timeSeries[0]+(duration-1);
        for(int i = 1; i < timeSeries.size(); ++i)
        {
            if(end >= timeSeries[i])
            {
                ret += duration-(end-timeSeries[i]+1); /* remove the overlap part */
                end = timeSeries[i]+(duration-1);
            }
            else
            {
                end = timeSeries[i]+(duration-1);
                ret += duration;
            }
        }
        return ret;
    }
};
