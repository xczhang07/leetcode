/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int curr = 0;
        int n = intervals.size();
        while(curr < n && intervals[curr].end < newInterval.start)
        {
            ret.push_back(intervals[curr]);
            ++curr;
        }
        while(curr < n && intervals[curr].start <= newInterval.end)
        {
            newInterval.start = min(newInterval.start, intervals[curr].start);
            newInterval.end = max(newInterval.end, intervals[curr].end);
            curr++;
        }
        ret.push_back(newInterval);
        while(curr < n)
        {
            ret.push_back(intervals[curr]);
            curr++;
        }
        return ret;
    }
};


/*a hard level algorithm issue on leetcode, using O(n) time complexity can resolve it, not too diffcult*/
