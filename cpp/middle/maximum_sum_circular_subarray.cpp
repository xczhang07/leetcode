Time Complexity is O(n)
Space Complexity is: O(1)
https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178413/c++-with-explaination.-O(n)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        if(A.size() == 0)
            return 0;
        else if(A.size() == 1)
            return A[0];
        int sum = 0;
        int sum_max = INT_MIN;
        int sum_min = INT_MAX;
        int tmp_sum = 0;
        int tmp_sum2 = 0;
        for(int i = 0; i < A.size(); ++i)
        {
            sum += A[i];
            tmp_sum += A[i];
            tmp_sum2 += A[i];
            sum_max = max(sum_max, tmp_sum);
            sum_min = min(sum_min, tmp_sum2);
            if(tmp_sum < 0)
                tmp_sum = 0;
            if(tmp_sum2 > 0)
                tmp_sum2 = 0;
        }
        if(sum == sum_min)
            return sum_max;
        int ret = max(sum_max, sum-sum_min);
        return ret;
    }
};
