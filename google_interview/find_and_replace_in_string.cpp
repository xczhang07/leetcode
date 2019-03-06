class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int,int>> sorted;
        for(int i = 0; i < indexes.size(); ++i)
            sorted.push_back(make_pair(indexes[i],i));
        
        sort(sorted.rbegin(), sorted.rend());
        
        for(auto e: sorted)
        {
            int i = e.first;
            int j = e.second;
            string s = sources[j];
            string t = targets[j];
            if(S.substr(i,s.size()) == s)
                S = S.substr(0, i) + t + S.substr(i+s.size());
        }
        
        return S;
    }
};
