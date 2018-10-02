class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int start = -1;
        int end = -1;
        int min_distance = INT_MAX;
        for(int i = 0; i < words.size(); ++i)
        {
            if(words[i] == word1)
                start = i;
            if(words[i] == word2)
                end = i;
            if(start >= 0 && end >= 0)
                min_distance = min(min_distance, abs(end-start));
        }
        return min_distance;
    }
};


/*
Conclusion, easy algorithm issue, no comments.
Time Complexity: O(n)
Space Complexity: O(1)
*/
