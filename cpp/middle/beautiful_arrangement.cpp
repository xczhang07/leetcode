class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N+1, false);
        int idx = 1;
        int cnt = 0;
        helper(visited, idx, N, cnt);
        return cnt;
    }
    
    void helper(vector<bool>& visited, int idx, int n, int& cnt)
    {
        if(idx > n)
        {
            cnt++;
            return;
        }
        for(int i = 1; i <= n; ++i)
        {
            if(!visited[i])
            {
                if(i%idx == 0 || idx%i == 0)
                {
                    visited[i] = true;
                    helper(visited, idx+1, n, cnt);
                    visited[i] = false;
                }
            }
        }
        return;
    }
};


Conclusion:
a middle level algorithm issue, it deserves middle level, I use backtracking to tackle this issue!
we created a help array "visited" to help keep track on the element whether or not has been resolved, for example, if in the position 1
we find out a number good for the rule, we just set visited[1] = true, and at the mean time, we create a variable idx to check whether or not
all the number from 1 to N has been full filled in the visited array. when idx is larger than N, it means all the elements fully filled up into
the array, and we find out a combination to meet the algorithm requirments.


Time Complexity:
O(k) ==> k is the combination number.
Space Complexity:
O(n)


a good resource as following:
https://leetcode.com/articles/beautiful-arrangement/
