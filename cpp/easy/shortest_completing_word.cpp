class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        unordered_map<char,int> m;
        for(auto s : licensePlate)
        {
            if((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
            {
                s = tolower(s);
                m[s]++;
            }
        }
        
        string ret;
        int min_len = INT_MAX;
        for(auto word : words)
        {
            unordered_map<char,int> tmp = m;
            for(auto c : word)
            {
                if(tmp.find(c) != tmp.end())
                {
                    tmp[c]--;
                    if(tmp[c] == 0)
                        tmp.erase(c);
                }
            }
            if(tmp.empty())
            {
                if(min_len > word.size())
                {
                    min_len = word.size();
                    ret = word;
                }
            }
        }
        return ret;
    }
};
