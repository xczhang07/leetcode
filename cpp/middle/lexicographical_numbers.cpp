class Solution {
public:
     vector<int> lexicalOrder(int n) {
        vector<int> ret;
        int num = 1;
        dfs(ret, num, n);
        return ret;
    }
    
    void dfs(vector<int>& ret, int num, int n)
    {
        if(num > n)
            return;
        ret.push_back(num);
        dfs(ret, num*10, n);
        if(num % 10 != 9)
            dfs(ret, num+1, n);
    }
};
