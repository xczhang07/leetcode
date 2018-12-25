class Solution {
public:
    void reverseWords(string &s) {
        reverseString(s, 0, s.size()-1); /* reverse the whole string */
        /* cut the leading and trailing spaces of the whole string */
        int start = 0;
        int end = s.size()-1;
        while(start < s.size() && s[start] == ' ')
            ++start;
        while(end >= 0 && s[end] == ' ')
            --end;
        s = s.substr(start, end-start+1);
        /* reverse the string word by word */
        start = 0;
        end = 0;
        while(end < s.size())
        {
            if(s[end] != ' ')
                ++end;
            else{
                reverseString(s, start, end-1);
                start = end+1;
                ++end;
            }
        }
        
        reverseString(s, start, end-1);
        /* remove extra space between each two words */
        removeExtraSpace(s);
        return;
    }
    
    void reverseString(string& s, int start, int end)
    {
        while(start < end)
        {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            ++start;
            --end;
        }
        return;
    }
    
    void removeExtraSpace(string& s)
    {
        int travel = 0;
        int cnt = 0;
        while(travel < s.size())
        {
            if(s[travel] != ' ')
                ++travel;
            else
            {
                int pos = travel;
                while(s[travel] == ' ')
                    ++travel;
                s.erase(pos, travel-1-pos);
            }
        }
        return;
    }
};

/*
a middle level algorithm issue, not too diffcult, just operation complicated, 
Time Complexity is: O(n)
Space Complexity is: O(1)
*/


Solution 2, much simpler and shorter of the code

class Solution {
public:
    void reverseWords(string &s) {
        int t = 0, l = 0, r = 0;
        int len = s.size();
        bool wordCount = 0;
        
        while(true)
        {
            while(t < len && s[t] == ' ')
                ++t;
            if(t == len)
                break;
            if(wordCount)
            {
                s[r] = ' ';
                ++r;
            }
            l = r;
            while(t < len && s[t] != ' ')
            {
                s[r] = s[t];
                ++t;
                ++r;
            }
            reverseWord(s, l, r-1);
            if(!wordCount) wordCount++;
        }
        s.resize(r);
        reverseWord(s, 0, r-1);
        return;
        
    }
    
    
    void reverseWord(string& s, int l, int r)
    {
        while(l < r)
        {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            ++l;
            --r;
        }
        return;
    }
    
   
};
