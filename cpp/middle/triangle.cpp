class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0 || triangle[0].size() == 0)
            return 0;
        vector<int> dp = triangle[triangle.size()-1];
        for(int i = triangle.size()-2; i >= 0; --i)
        {
            for(int j = 0; j < triangle[i].size(); ++j)
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
        }
        return dp[0];
    }
    
    
};

/*
Time Complexity is: O(m*n)
Space Complexity is: O(n)
*/
