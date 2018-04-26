class Solution {
public:
    /* search the nearest charactor equals c in s around start position */
    int search_position(string& s, char& c, int start)
    {
        int left = start;
        int right = start;
        if(s[start] == c)
            return start;
        while(left >= 0 || right < s.size())
        {
            if(left >= 0 && s[left] == c)
                return left;
            else if(right < s.size() && s[right] == c)
                return right;
            --left;
            ++right;
        }
        return -1;
    }
    
    vector<int> shortestToChar(string S, char C) {
        vector<int> min_dist;
        for(int i = 0; i < S.size(); ++i)
        {
            int pos = search_position(S, C, i);
            min_dist.push_back(abs(pos-i));
        }
        return min_dist;
    }
};

Conclusion:
an easy leetcode algorithm issue, we implement the fast-search helper function, which will get the 
nearest charactor(which value is c) close to the position i, then caculate the absolute distance
between the charactor and i.

Time Complexity: O(n^2)
Space Complexity: O(1)
