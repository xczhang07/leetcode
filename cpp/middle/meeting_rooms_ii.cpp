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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() < 2)
            return intervals.size();
        map<int,int> m; /* map is sorted which unlike unordered_map */
        for(auto i : intervals)
        {
            m[i.start]++;
            m[i.end]--;
        }
        int max_room = 0;
        int ret = 0;
        for(auto e : m)
        {
            ret = max(ret, max_room+=e.second);
        }
        return ret;
    }
};




Solution3: O(m+n) time complexity
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
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0)
            return 0;
        int max_time = 0;
        for(int i = 0; i < intervals.size(); ++i)
            max_time = max(max_time, intervals[i].end);
        vector<int> times(max_time+1, 0);
        int rooms = 1;
        int count = 0;
        for(int i = 0; i < intervals.size(); ++i)
        {
            times[intervals[i].start]++;
            times[intervals[i].end]--;
        }
        for(int i = 0; i <= max_time; ++i)
        {
            count += times[i];
            rooms = max(rooms, count);
        }
        return rooms;
    }
};
