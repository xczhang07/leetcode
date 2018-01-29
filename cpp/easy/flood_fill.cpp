class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size() == 0)
            return image;
        if(image[0].size() == 0)
            return image;
        int oldColor = image[sr][sc];
        if(image[sr][sc] != newColor)
            dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int x, int y, int& oldColor, int& newColor)
    {
        if(x > image.size()-1 || x < 0 || y > image[0].size()-1 || y < 0)
            return;
        if(image[x][y] == oldColor)
            image[x][y] = newColor;
        else
            return;
        dfs(image, x-1, y, oldColor, newColor);
        dfs(image, x+1, y, oldColor, newColor);
        dfs(image, x, y-1, oldColor, newColor);
        dfs(image, x, y+1, oldColor, newColor);
        return;
    }
};


Conclusion:
This issue is not a complicated algorithm issue, using dfs for this issue is the best choice. According to the given starting pixel (sr,sc), if the color at (sr, sc) position is not equal to the newColor(input), then we need to navigate to the four directions of the position: (sr-1, sc), (sr+1, sc), (sr, sc-1), (sr, sc+1).

Time Complexity is: O(m*n)
Space Complexity is: O(1) except for the recursive stack.

