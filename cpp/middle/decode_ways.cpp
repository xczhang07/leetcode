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
