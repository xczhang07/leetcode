Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

Example 1:

Input: [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: [[7,10],[2,4]]
Output: true


Time Complexity is: O(n)
Space Complexity is: O(1)

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
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return true;
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < intervals.size()-1; ++i)
        {
            if(intervals[i].end > intervals[i+1].start)
                return false;
        }
        return true;
    }
};
