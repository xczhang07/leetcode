class Solution {
public:
    string toGoatLatin(string S) {
        string ret;
        if(S.size() == 0)
            return S;
        vector<string> words;
        split(S, words);
        string tmp = "ma";
        int cnt = 1;
        for(int i = 0; i < words.size(); ++i)
        {
            char f = tolower(words[i][0]);
            if(f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u')
                ret = ret + words[i]+tmp;
            else
                ret = ret + words[i].substr(1) + words[i][0] + tmp;
            
            ret.append(cnt, 'a');
            if(i != words.size()-1)
                ret += " ";
            cnt++;
        }
        return ret;
    }
    
    void split(string& s, vector<string>& words)
    {
        int i = 0;
        int t = 0;
        while(t < s.size())
        {
            if(s[t] == ' ')
            {
                words.push_back(s.substr(i, t-i));
                i = t+1;
            }
            ++t;
        }
        
        words.push_back(s.substr(i, t-i+1));
        return;
    }
};
