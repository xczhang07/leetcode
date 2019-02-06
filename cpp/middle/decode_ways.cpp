class Solution {
public:
    int numDecodings(string s) {
        /*
            d[i]: number of combinations at index i
            d[0] = 1
            d[1] = 1 if s[0] is is NOT 0
            Initially set d[i] to zero, and add the following values to it if the condition is true:
            Add d[i-1] to d[i], If the one-digit number from s[i-1] is a valid one-digit number (i.e. non-zero)
            Add d[i-2] to d[i], If the two-digit number from s[i-2] is a valid two-digit number (i.e. 10 to 26)
            Return d[N]
        */
        if(s.size() == 0 || (s.size() > 1 && s[0] == '0'))
            return 0;
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0' ? 0:1);
        for(int i = 2; i <= s.size(); ++i)
        {
            int n1 = stoi(s.substr(i-1,1));
            int n2 = stoi(s.substr(i-2,2));
            if(n1 != 0)
                dp[i] += dp[i-1];
            if(n2 > 9 && n2 <= 26)
                dp[i] += dp[i-2];
        }
        return dp.back();
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/


/*
Space Complexity is O(1) version

3 cases:

case1:
1->9 decode method is 1.
10, 20: decode method is 1.
11->19, 21->26: decode method is 2

https://leetcode.com/problems/decode-ways/discuss/202814/Java-O(1)-Space-O(n)-Time
*/

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 0;
        int prev = 1;
        int curr = 0;
        int pprev = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i > 0 && (s[i-1] == '1' || (s[i-1] == '2' && (s[i]-'0' <= 6))))
            {
                if(s[i] == '0')
                    curr = pprev;
                else
                    curr = prev + pprev;
            }
            else if(s[i] == '0')
                return 0;
            else if(s[i] >= '1' && s[i] <= '9')
                curr = prev;
            pprev = prev;
            prev = curr;
        }
        return curr;
    }
};
