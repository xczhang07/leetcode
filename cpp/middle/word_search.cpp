class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return false;
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                bool ret = dfs(board, word, 0, i, j);
                if(ret)
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int idx, int i, int j)
    {
        if(idx == word.size())
            return true;
        if(i < 0 || j < 0 || i > board.size()-1 || j > board[0].size()-1)
            return false;
        if(board[i][j] != word[idx])
            return false;
        
        char c = board[i][j];
        board[i][j] = '#';
       bool res = dfs(board, word, idx + 1, i - 1, j) 
                 || dfs(board, word, idx + 1, i + 1, j)
                 || dfs(board, word, idx + 1, i, j - 1)
                 || dfs(board, word, idx + 1, i, j + 1);
        board[i][j] = c;
        return res;
    } 
};
