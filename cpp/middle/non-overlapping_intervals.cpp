/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval i1, Interval i2)
{
    if(i1.start == i2.start)
        return i1.end < i2.end;
    else
        return i1.start < i2.start;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int t = 1;
        int ret = 0;
        int i = 0;
        while(t < intervals.size())
        {
            if(intervals[t].start < intervals[i].end)
            {
                ++ret;
                if(intervals[t].end < intervals[i].end) /* greedy algorithm, point to the interval which cover less space */
                    i =t;
            } 
            else 
                i = t;
            t++;
        }
        return ret;
    }
};
