class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0; 
        if(board.size() == 0)
            return ret;
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] == 'X')
                {
                    if((i == board.size()-1 || board[i+1][j] == '.') && (j == board[i].size()-1 || board[i][j+1] == '.'))
                        ret++;
                }
            }
        }
        return ret;
    }
};

Conclusion:
easy, no comments
