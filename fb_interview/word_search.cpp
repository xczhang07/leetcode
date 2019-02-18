class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int idx, int i, int j)
    {
        if(idx == word.size())
            return true;
        if(idx > word.size())
            return false;
        int n = board.size();
        int m = board[0].size();
        char tmp = board[i][j];
        board[i][j] = '#';
        vector<pair<int,int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        bool ret = false;
        for(auto d : dirs)
        {
            int x = d.first + i;
            int y = d.second + j;
            if(x < 0 || x >= n || y < 0 || y >= m || board[x][y] == '#')
                continue;
            if(board[x][y] == word[idx])
            {
                bool ret = dfs(board, word, idx+1, x, y);
                if(ret)
                    return true;
            }
        }
        board[i][j] = tmp;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)
            return true;
        if(board.size() == 0 || board[0].size() == 0)
            return false;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] == word[0])
                {
                    bool ret = dfs(board, word, 1,i, j);
                    if(ret)
                        return true;
                }
            }
        }
        return false;
    }
};
