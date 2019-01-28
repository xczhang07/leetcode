/*
Time Complexity is: O(n)
Space Complexity is: O(1)
*/

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
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        auto iter = intervals.begin();
        while(iter != intervals.end())
        {
            /* case1: newInterval.end < iter->start, the right place to insert */
            if(newInterval.end < iter->start)
            {
                intervals.insert(iter, newInterval);
                return intervals;
            }
            else if(newInterval.start > iter->end) /* case2: newInterval.start > iter->end */
                iter++;
            else
            {
                newInterval.start = min(newInterval.start, iter->start);
                newInterval.end = max(newInterval.end, iter->end);
                iter = intervals.erase(iter);
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/

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
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        vector<Interval> ret;
        int idx = 0;
        while(idx < intervals.size())
        {
            if(intervals[idx].end < newInterval.start)
                ret.push_back(intervals[idx++]);
            else
                break;
        }
        
        while(idx < intervals.size())
        {
            if(intervals[idx].start <= newInterval.end && intervals[idx].end >= newInterval.start)
            {
                newInterval.start = min(newInterval.start, intervals[idx].start);
                newInterval.end = max(newInterval.end, intervals[idx].end);
                ++idx;
            }
            else
                break;
        }
        
        ret.push_back(newInterval);
        while(idx < intervals.size())
        {
            ret.push_back(intervals[idx++]);
        }
        return ret;
    }
};


/*
Solution #3:
Time Complexity is: best case: O(logN)
worst case O(N)

Space Complexity is: O(1)
*/

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
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int insert_pos = binary_search(intervals, newInterval.start);
        vector<Interval>::iterator iter = intervals.begin() + insert_pos;
        while(iter != intervals.end())
        {
            if(newInterval.end < iter->start)
            {
                intervals.insert(iter, newInterval);
                return intervals;
            }
            else if(newInterval.start > iter->end)
                ++iter;
            else
            {
                newInterval.start = min(newInterval.start, iter->start);
                newInterval.end = max(newInterval.end, iter->end);
                iter = intervals.erase(iter);
            }
        }
        intervals.push_back(newInterval);
        return intervals;
        
    }
    
    int binary_search(vector<Interval>& intervals, int target)
    {
        int l = 0, r = intervals.size()-1;
        while(l <= r)
        {
            int m = l + (r-l)/2;
            if(intervals[m].start == target)
                return m;
            else if(intervals[m].start < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        return r < 0 ? 0: r;
    }
};
