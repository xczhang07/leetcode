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
    vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
        int i = 0;
        int j = 0;
        vector<Interval> ret;
        while(i < A.size() && j < B.size())
        {
            if(A[i].start > B[j].end)
                ++j;
            else if(B[j].start > A[i].end)
                ++i;
            else
            {
                int start = max(A[i].start, B[j].start);
                int end = min(A[i].end, B[j].end);
                ret.push_back(Interval(start, end));
                if(A[i].end < B[j].end)
                    ++i;
                else
                    ++j;
            }
        }
        return ret;
    }
};

Time Complexity is: O(min(len(A), len(B)))
Space Complexity is: O(n)
