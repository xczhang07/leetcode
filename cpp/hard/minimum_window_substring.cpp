class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n > m) {
            return "";
        }
        string ret;
        int min_len = INT_MAX;
        unordered_map<char, int> letter_map;
        for(char c: t) {
            letter_map[c]++;
        }
        int start = 0;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i) {
            letter_map[s[i]]--;
            if(letter_map[s[i]] >= 0) {
                ++cnt;
            }
            
            while(cnt == n) {
                // Cover the memory limit test case error.
                while(letter_map[s[start]]+1 <= 0) 
                {
                    letter_map[s[start]]++;
                    ++start;
                }
                int tmp_len = i - start + 1;
                if(tmp_len < min_len) {
                    min_len = tmp_len;
                    ret = s.substr(start, min_len);
                }
                letter_map[s[start]]++;
                if(letter_map[s[start]] > 0) {
                    --cnt;
                }
                ++start;
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



