class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    if(board.size() == 0 || board[0].size() == 0)
        return;
    int n = board.size();
    int m = board[0].size();
    
    map<pair<int,int>,bool> map;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(board[i][j])
                map[make_pair(i,j)] = true;
            else
                map[make_pair(i, j)] = false;
        }
    }
    
    vector<pair<int,int>> dirs = {{-1,-1}, {0,-1}, {1,-1}, {-1, 0}, {1,0}, {-1,1}, {0,1}, {1,1}};
    for(int i = 0; i < n; ++i)
    {
        int zero = 0;
        int one = 0;
        for(int j = 0; j < m; ++j)
        {
            zero = 0;
            one = 0;
            for(auto dir : dirs)
            {
                int x = i + dir.first;
                int y = j + dir.second;
                if(map.count({x,y}))
                {
                    if(map[{x,y}] == true)
                        one++;
                    else
                        zero++;
                }
            }
            
            if(one < 2)
                board[i][j] = 0;
            else if(one > 3)
            {
                if(board[i][j] == 1)
                    board[i][j] = 0;
            }
            else if(one == 3 && board[i][j] == 0)
                board[i][j] = 1;
        }
    }
    return;
}
};
