class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(s.size() < t.size())
            swap(s, t);
        int m = s.size();
        int n = t.size();
        int diff = m - n;
        if(diff >= 2)
            return false;
        if(diff == 1)
        {
            for(int i = 0; i < t.size(); ++i)
            {
                if(s[i] != t[i])
                    return s.substr(i+1) == t.substr(i);
            }
            return true;
        }
        else
        {
            int cnt = 0;
            for(int i = 0; i < t.size(); ++i)
            {
                if(s[i] != t[i])
                {
                    ++cnt;
                    if(cnt > 1)
                        return false;
                }
            }
            return cnt == 1;
        }
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
