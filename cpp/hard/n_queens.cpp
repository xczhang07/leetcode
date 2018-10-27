class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<int> pos(n, -1);
        dfs(ret, pos, n, 0);
        return ret;
    }
    
    void dfs(vector<vector<string>>& ret, vector<int>& pos, int& n, int row)
    {
        if(row == n)
        {
            vector<string> queens(n, string(n, '.'));
            for(int i = 0; i < n; ++i)
                queens[i][pos[i]] = 'Q';
            ret.push_back(queens);
            return;
        }
        else
        {
            for(int col = 0; col < n; ++col)
            {
                bool is_valid = canPut(pos, row, col);
                if(is_valid)
                {
                    pos[row] = col;
                    dfs(ret, pos, n, row+1);
                    pos[row] = -1;
                }
            }
        }
        return;
    }
    
    
    bool canPut(vector<int>& pos, int& row, int& col)
    {
        for(int i = 0; i < row; ++i)
        {
            if(pos[i] == col || abs(i-row) == abs(pos[i]-col))
                return false;
        }
        return true;
    }
};

/*
classic n-queens algorithm issue, using backtracking to resolve it.
array pos is used to record the queen put at row i and column at pos[i]

*/
