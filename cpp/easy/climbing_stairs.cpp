class Solution {
public:
    int climbStairs(int n) {
        // easy dynamic programming issue
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        vector<int> stairs(n+1, 0);
        stairs[1] = 1;
        stairs[2] = 2;
        for(int i = 3; i <= n; ++i)
            stairs[i] = stairs[i-1] + stairs[i-2];
        return stairs[n];
    }
};

Conclusion:
a easy algoritm issue, but it needs dynamic programming concept.
1. create a vector with size n+1 (because we have n stairs, each index is caculate each level's climbing ways)
2. initial the stairs value, if it has only one stair, the value is 1; if it has two stairs, the climbing ways is 2.
3. then use the dynamic formula: stairs[n] = stairs[n-1] + stairs[n-2] to caculate each level (start from 3)
4. finally, return the stairs[n]


Time Complexity: O(n)
Space Complexity: O(n)
