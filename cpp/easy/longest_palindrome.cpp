class Solution {
public:
    int longestPalindrome(string s) {
        int odds = 0;
        for(char c = 'A'; c <= 'z'; ++c)
            odds += count(s.begin(), s.end(), c) & 1;
        
        return s.size() - odds + (odds > 0);
    }
};

Conclusion:
caculate the frequence number of each charactor in the input string, caculate how many charactor appear odd times, then using the total length of the array
minus the odd times, if the odd is greater than 1, then we need to plus 1 to the final result.

a math algorithm issue. 
