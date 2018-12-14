class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> res(G+1, vector<int>(P+1, 0));
        res[0][0] = 1;
        int n = group.size(), mod = 1e9 + 7;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = G; j >= group[i]; --j)
            {
                for(int k = P; k >= 0; --k)
                {
                    res[j][k] = (res[j][k] + res[j-group[i]][max(0, k-profit[i])]) % mod;
                }
            }
        }
        
        int sum = 0;
        for(int i = 1; i <= G; ++i)
            sum = (sum + res[i][P]) % mod;
        return sum;
    }
};


/*
time complexity is: O(npg)

reference link as: https://blog.csdn.net/AzureoSky/article/details/84112373
*/
