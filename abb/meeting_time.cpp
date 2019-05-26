Leetcode 相似问题: Leetcode 252/253 Meeting Rooms I/II http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=146537
给一组 meetings(每个 meeting 由 start 和 end 时间组成)。求出在所有输入 meeting 时间段内没有 会议，也就是空闲的时间段。每个 subarray 都已经 sort 好。
举例:
[[1, 3], [6, 7]], [[2, 4]], [[2, 3], [9, 12]]
返回
[[4, 6], [7, 9]]
这题最简单的方法就是把所有区间都拆成两个点，然后排序，然后扫􏰁，每次碰到一个点如果是 左端点就把 busy_employees 加 1，否则减 1，等到每次 busy_employees 为 0 时就是一个新的区 间。这样复杂度 O(MlogM)，M 是总共区间数。
follow up: 求不少于 k 个员工空闲的时间段(改一下 check count 的条件就可以了)

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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        if(schedule.size() == 0)
            return {};
        vector<Interval> ret;
        map<int,int> m;
        for(int i = 0; i < schedule.size(); ++i)
        {
            for(int j = 0; j < schedule[i].size(); ++j)
            {
                int start = schedule[i][j].start;
                int end = schedule[i][j].end;
                m[start]++;
                m[end]--;
            }
        }
        
        int cnt = 0;
        for(auto e: m)
        {
            cnt += e.second;
            if(cnt == 0)
                ret.push_back(Interval(e.first, 0));
            else if(cnt != 0 && !ret.empty() && ret.back().end == 0)
                ret.back().end = e.first;
        }
        
        if(!ret.empty())
            ret.pop_back();
        return ret;
    }
};
