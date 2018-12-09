class Solution {
public:
     bool isNumber(string s) {
         if(s.size() == 0)
             return false;
         int start = 0;
         int end = s.size()-1;
         while(s[start] == ' ') ++start;
         while(s[end] == ' ') --end;
         if(s[start] == '-' || s[start] == '+') ++start;
         if(start > end) return false;
         bool isdot = false;
         bool ise = false;
         for(int i = start; i <= end; ++i)
         {
             if(s[i] == '.')
             {
                 if(start == end) return false;
                 if(isdot || ise) return false;
                 isdot = true;
             }
             else if(s[i] == 'e')
             {
                 if(i == start || i == end) return false;
                 if(s[i-1] == '.' && i-1 == start) return false;
                 if(ise) return false;
                 ise = true;
             }
             else if(s[i] >= '0' && s[i] <= '9') continue;
             else if(s[i] == '+' || s[i] == '-')
             {
                 if(s[i-1] != 'e' || i == end) return false;
             }
             else return false;
         }
         return true;
    }
};
