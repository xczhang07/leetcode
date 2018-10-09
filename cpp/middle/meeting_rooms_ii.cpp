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
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() < 2)
            return intervals.size();
        sort(intervals.begin(), intervals.end(), compareInterval);
        priority_queue<int,vector<int>, greater<int>> min_q;
        for(auto i : intervals)
        {
            if(!min_q.empty())
            {
                if(min_q.top() <= i.start)
                    min_q.pop();
            }
            min_q.push(i.end);
        }
        return min_q.size();
    }
};

/*
we can use min priority queue to resolve this issue.
*/
