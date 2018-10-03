class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx1 = -1;
        int idx2 = -1;
        int min_distance = INT_MAX;
        for(int i = 0; i < words.size(); ++i)
        {
            if(word1 == words[i])
                idx1 = i;
            if(word2 == words[i])
            {
                if(word1 == word2)
                    idx1 = idx2;
                idx2 = i;
            }
            if(idx1 >= 0 && idx2 >= 0)
                min_distance = min(min_distance, abs(idx1-idx2));
        }
        return min_distance;
    }  
};


/*
Conclusion: an middle level algorithm issue, not diffcult.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
