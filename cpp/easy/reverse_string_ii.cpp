 class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.size() == 0 || s.size() == 1)
            return s;
        int start = 0;
        int end = k-1;
        while(1)
        {
            //check whether or not the input string size is less than integer k
            if(s.size() <= k)
            {
                reverse_string(s, start, s.size()-1);
                break;
            }
            reverse_string(s, start, end);
            if(start+2*k < s.size()-1 && end+2*k > s.size()-1)
            {
                reverse_string(s, start+2*k, s.size()-1);
                break;
            }
            else if(start+2*k >= s.size()-1)
                break;
            else{
                start = start + (2*k);
                end = end + (2*k);
            }
            
        }
        return s;
    }
    
    void reverse_string(string& s, int start, int end)
    {
        if(start >= end)
            return;
        while(start < end)
        {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            ++start;
            --end;
        }
    }
};

Conclusion:
easy
