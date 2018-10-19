class Solution {
public:
    string minWindow(string s, string t) {
        string ret = "";
        int cnt = 0;
        int left = 0;
        int min_len = INT_MAX;
        unordered_map<char, int> letterCnt;
        for(char c : t)
            letterCnt[c]++;
        for(int i = 0; i < s.size(); ++i)
        {
            --letterCnt[s[i]];
            if(letterCnt[s[i]] >= 0)
                cnt++;
            while(cnt == t.size())
            {
                if(i-left+1 < min_len)
                {
                    min_len = i - left + 1;
                    ret = s.substr(left, min_len);
                }
                letterCnt[s[left]]++;
                if(letterCnt[s[left]] > 0)
                    cnt--;
                left++;
            }
        }
        return ret;
    }
};


/*
Conclusion: a hard level issue on leetcode, using sliding window concept to resolve this issue.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
