// time complexity is: O(nlogn)
// Space complexity is: O(n)
bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
}

class Solution {
public:
    // find the last job whose end time is not large than the begin time of job[i]
    int binarySearch(vector<vector<int>>& jobs, int right, int target) {
        int left = 0;
        int ret = 0;
        while(left <= right) {
            int mid = (right-left)/2 + left; // avoid the overflow.
            if(jobs[mid][1] <= target) {
                ret = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        if(left == 0) {
            return -1;
        }
        return ret;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        int n = startTime.size();
        for(int i = 0; i < n; ++i) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), compare);
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1];
            // find the last job not conflict with job[i], which means the target job end time <= job[i].startTime.
            int start = jobs[i-1][0];
            int lastNoConflictJobIndex = binarySearch(jobs, i-2, start);
            dp[i] = max(dp[i-1], dp[lastNoConflictJobIndex+1]+jobs[i-1][2]);
        }
        return dp[n];
    }
};
