class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) 
   {
       if (T[s[i]] < T[s[i + 1]])
       {
           sum -= T[s[i]];
       }
       else
       {
           sum += T[s[i]];
       }
   }
   
   return sum;
    }
};


Conclusion:
an easy algorithm issue. No comments.

    Solution II:
    
    class Solution {
public:
    int romanToInt(char c)
    {
        if(c == 'I')
            return 1;
        else if(c == 'V')
            return 5;
        else if(c == 'X')
            return 10;
        else if(c == 'L')
            return 50;
        else if(c == 'C')
            return 100;
        else if(c == 'D')
            return 500;
        else if(c == 'M')
            return 1000;
        else
            return 0;
    }
    
    int romanToInt(string s) {
        int num = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(i < s.size()-1 && romanToInt(s[i]) < romanToInt(s[i+1]))
                num -= romanToInt(s[i]);
            else
                num += romanToInt(s[i]);
        }
        return num;
    }
};
