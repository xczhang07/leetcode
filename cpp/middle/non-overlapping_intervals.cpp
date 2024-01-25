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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int t = 1;
        int ret = 0;
        int i = 0;
        while(t < intervals.size())
        {
            if(intervals[t].start < intervals[i].end)
            {
                ++ret;
                if(intervals[t].end < intervals[i].end) /* greedy algorithm, point to the interval which cover less space */
                    i =t;
            } 
            else 
                i = t;
            t++;
        }
        return ret;
    }
};


// Using greed algorithm to sort the end of the intervals.
// More details please refer to https://github.com/changgyhub/leetcode_101/blob/master/LeetCode%20101%20-%20A%20LeetCode%20Grinding%20Guide%20(C%2B%2B%20Version).pdf

class Solution {
public:

   
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[1] < v2[1];
        });
        int prev = intervals[0][1];
        int removed = 0;
        for(int i = 1; i < intervals.size(); ++i) {
            if(prev > intervals[i][0]) {
                ++removed;
            } else {
                prev = intervals[i][1];
            }
        }
        return removed;  
    }
};
