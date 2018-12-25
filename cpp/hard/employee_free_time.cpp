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


/*
Solution2, similiar question with meeting room ii.
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
        map<int, int> m;
        for(int i = 0; i < schedule.size(); ++i)
        {
            for(int j = 0; j < schedule[i].size(); ++j)
            {
                m[schedule[i][j].start]++;
                m[schedule[i][j].end]--;
            }
        }
        
        int cnt = 0;
        for(auto e : m)
        {
            cnt += e.second;
            if(cnt == 0)
                ret.push_back(Interval(e.first, 0));
            if(cnt != 0 && ret.size() != 0 && ret.back().end == 0)
                ret.back().end = e.first;
        }
        if(ret.size() != 0)
            ret.pop_back();
        return ret;
    }
};


