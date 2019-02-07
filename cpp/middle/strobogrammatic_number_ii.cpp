class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return find(n,n);
    }
    
    vector<string> find(int m, int n)
    {
        if(m == 0)
            return {""};
        if(m == 1)
            return {"0", "1", "8"};
        vector<string> l = find(m-2, n);
        vector<string> res;
        for(int i = 0; i < l.size(); ++i)
        {
            if(m != n)
                res.push_back("0"+l[i]+"0");
            res.push_back("1"+l[i]+"1");
            res.push_back("8"+l[i]+"8");
            res.push_back("9"+l[i]+"6");
            res.push_back("6"+l[i]+"9");
        }
        
        return res;
    }
};
