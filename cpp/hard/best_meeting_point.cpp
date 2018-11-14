class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        if(grid[0].size() == 0)
            return 0;
        
        vector<int> rows;
        vector<int> cols;
        
        /* get the row and col index of each person */
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j])
                {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        return (caculateMinDistance(rows) + caculateMinDistance(cols));
    }
    
    int caculateMinDistance(vector<int>& input)
    {
        if(input.size() == 0)
            return 0;
        sort(input.begin(), input.end());
        int dist = 0;
        int i = 0;
        int j = input.size()-1;
        while(i < j)
        {
            dist += (input[j]-input[i]);
            ++i;
            --j;
        }
        return dist;
    }
};


/*
Time Complexity is: O(n^2)
Space Complexity is: O(n)
*/
