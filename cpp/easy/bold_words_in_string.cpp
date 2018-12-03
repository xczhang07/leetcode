class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        if(words.size() == 0)
            return "";
        if(S.size() == 0)
            return "";
        string ret = "";
        int n = S.size();
        vector<bool> bold(n, false);
        for(auto word : words)
        {
            int len = word.size();
            for(int i = 0; i <= n-len; ++i)
            {
                if(word[0] == S[i] && S.substr(i, len) == word)
                {
                    for(int j = i; j < i+len; ++j)
                        bold[j] = true;
                }
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(bold[i])
            {
                if(i == 0 || bold[i-1] == false)
                    ret += "<b>";
                ret.push_back(S[i]);
                if(i == n-1 || bold[i+1] == false)
                    ret += "</b>"; 
            }
            else
            {
                ret.push_back(S[i]);
            }
        }
        return ret;
    }
};
