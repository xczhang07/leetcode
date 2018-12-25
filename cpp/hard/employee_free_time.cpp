/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

/*
Solution 1: same as merge Interval. do some modification.
*/

bool compare(Interval& i1, Interval& i2)
{
    return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> ret;
        if(schedule.size() == 0)
            return ret;
        vector<Interval> combine;
        for(auto s : schedule)
            combine.insert(combine.end(), s.begin(), s.end());
        sort(combine.begin(), combine.end(), compare);
        int end = combine[0].end;
        for(int i = 1; i < combine.size(); ++i)
        {
            if(combine[i].start > end)
            {
                ret.push_back(Interval(end, combine[i].start));
                end = combine[i].end;
            }
            else
                end = max(end, combine[i].end);
        }
        return ret;
    }
};

