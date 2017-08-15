class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ret = 0;
        int cnt = 0;
        for(int i = 2; i < A.size(); ++i)
        {
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
            {
                ++cnt;
                ret += cnt;
            }
            else
                cnt = 0;
        }
        return ret;
    }
};


Conclusion:
a middle level algorithm issue. Not a difficult issue.
Time Complexity: O(n)
Space Complexity: O(1)

more info plz check the following site:
http://www.cnblogs.com/grandyang/p/5968340.html
