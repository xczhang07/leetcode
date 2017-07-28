class Solution {
public:
    bool checkRecord(string s) {
        int condition_a = 0;
        int condition_b = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == 'A')
            {
                ++condition_a;
                if(condition_a > 1)
                    break;
            }
            if(s[i] == 'L')
            {
                if(i < s.size()-2)
                {
                    if(s[i+1] == 'L' && s[i+2] == 'L')
                    {
                        condition_b = 1;
                        break;
                    }
                }
            }
        }
        if (condition_a > 1 || condition_b == 1)
            return false;
        else
            return true;
    }
};

Conclusion:
easy algorithm issue. 
Time Complexity is: O(n)
Space Complexity is: O(1)
