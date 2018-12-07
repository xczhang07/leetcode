class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0)
            return 0;
        if(citations.size() == 1 && citations[0] == 0)
            return 0;
        sort(citations.begin(), citations.end());
        int n = citations.size()-1;
        for(int i = 0; i < citations.size(); ++i)
        {
            if(citations[i] >= n-i+1)
                return n-i+1;
        }
        return 0;
    }
};

 
