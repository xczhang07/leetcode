/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compareInterval(Interval& i1, Interval& i2)
{
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        if(intervals.size() == 0)
            return ret;
        sort(intervals.begin(), intervals.end(), compareInterval);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(intervals[i].start <= end)
                end = max(end, intervals[i].end);
            else
            {
                ret.push_back(Interval(start,end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        ret.push_back(Interval(start, end));
        return ret;
    }
};


Conclustion: a middle level algorithm issue on leetcode, not diffcult, my approach as following:
1. sort the intervals.
2. get the "start" and "end" value of the first element in the input intervals array.
3. merge the element one by one.

Time Complexity: O(n)
Space Complexity: O(n)
