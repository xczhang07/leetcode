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
    return (i1.start < i2.start);
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return true;
        sort(intervals.begin(), intervals.end(), compareInterval);
        int start = intervals[0].start;
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i)
        {
            if(end <= intervals[i].start)
            {
                start = intervals[i].start;
                end = intervals[i].end;
            }
            else
                return false;
        }
        return true;
    }
};


Conclusion:
Not a diffcult algorithm issue, sort the intervals, and then compare each end value
Time Complexity: O(n)
Space Complexity: O(1)
