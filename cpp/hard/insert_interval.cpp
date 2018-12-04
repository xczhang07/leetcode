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

/* 2nd solution */

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
        if(intervals.size() == 0)
            return {newInterval};
        vector<Interval>::iterator it = intervals.begin();
        while(it != intervals.end())
        {
            if(newInterval.end < it->start)
            {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else if(it->end < newInterval.start)
                it++;
            else
            {
                newInterval.start = min(newInterval.start, it->start);
                newInterval.end = max(newInterval.end, it->end);
                intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};

