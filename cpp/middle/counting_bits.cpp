class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        for(int i = 0; i <= num; ++i)
        {
            int count = getBits(i);
            ret.push_back(count);
        }
        return ret;
    }
    
    int getBits(int num)
    {
        if(num == 0)
            return 0;
        int count = 0;
        while(num != 0)
        {
            if((num & 1) != 0)
                ++count;
            num >>= 1;
        }
        return count;
    }
};


Conclusion:
I think this algorithm issue is an easy level issue. implement a helper function to caculate each number's 1 number.
key point: using x & 1 == 1, we can check whether or not x is 1 at the rightest position because 1's binary version is: 00000001


Time complexity: O(n*sizeof(num))
Space complexity: O(1)

class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0)
            return {0};
        vector<int> dp(num+1, 0);
        dp[0] = 0;
        for(int i = 1; i <= num; ++i)
        {
            dp[i] = dp[i/2] + (i%2);
        }
        return dp;
    }
};

Time Complexity is: O(n)
space complexity is: O(1)
