class Solution {
public:
    
    vector<int> diStringMatch(string S) 
    {
        int min = 0, max = S.size();
        vector<int> res;
        
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == 'I') 
                res.push_back(min++);
            if (S[i] == 'D') 
                res.push_back(max--);
        }
        res.push_back(min++);
        
        return res;
    }
};
