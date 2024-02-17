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

Update the code based on the interface changed
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            if(v1[0] < v2[0]) {
                return true;
            } else if(v1[0] == v2[0]) {
                return v1[1] < v2[1];
            } else {
                return false;
            }
        });
        vector<vector<int>> merged_intervals;
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i) {
            if(end < intervals[i][0]) {
                merged_intervals.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            } else {
                end = max(end, intervals[i][1]);
            }
        }
        merged_intervals.push_back({start, end});
        return merged_intervals;
    }
};
