class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        if(!s.size())
            return ret;
        for(char e:s)
        {
            ret *= 26;
            ret = ret + e - 'A' + 1;
        }
        return ret;
    }
};


Conclusion:
easy question, a math problem, the key formula is: ret += e-'A'+1;


Time Complexity: O(n)
Space Complexity: O(1)
