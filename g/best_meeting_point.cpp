A group of two or more people wants to meet and minimize the total travel distance. 
You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. 
  The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example:

Input: 

1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 6 

Explanation: Given three people living at (0,0), (0,4), and (2,2):
             The point (0,2) is an ideal meeting point, as the total travel distance 
             of 2+2+2=6 is minimal. So return 6.

class Solution {
public:
    int calculateMinDistance(vector<int> input)
    {
        int i = 0;
        int j = input.size()-1;
        sort(input.begin(), input.end());
        int dist = 0;
        while(i < j)
        {
            dist += (input[j]-input[i]);
            ++i;
            --j;
        }
        return dist;
    }
    
    
    int minTotalDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row;
        vector<int> col;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(grid[i][j] == 1)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        
        return (calculateMinDistance(row) + calculateMinDistance(col));
    }
};
