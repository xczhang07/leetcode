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
        map<int, int> m;
        int rooms = 0;
        for(auto e: intervals)
        {
            m[e.start]++;
            m[e.end]--;
        }
        int tmp = 0;
        for(auto e: m)
        {
            tmp += e.second;
            rooms = max(rooms, tmp);
        }
        return rooms;
    }
};
