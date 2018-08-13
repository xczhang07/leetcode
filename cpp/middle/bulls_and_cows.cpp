class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0;
        int cow = 0;
        unordered_map<char, int> my_map;
        int len = secret.size();
        /* caculate the bull's number */
        for(int i = 0; i < len; ++i)
        {
            if(secret[i] == guess[i])
                ++bull;
            my_map[secret[i]]++;
        }
        /* caculate the cow's number */
        for(int j = 0; j < len; ++j)
        {
            if(my_map.find(guess[j]) != my_map.end() && my_map[guess[j]] > 0)
            {
                ++cow;
                my_map[guess[j]]--;
            }
        }
        return to_string(bull)+"A"+to_string(cow-bull)+"B";
    }
};


Conclusion: an middle level algorithm issue, it is not diffcult, just caculate the bulls number, then caculate the cow's number
Time Complexity: O(n)
Space Complexity: O(n)
