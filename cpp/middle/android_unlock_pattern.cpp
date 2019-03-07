class Solution {
public:
    int numberOfPatterns(int m, int n) {
        if(m == 1 && n == 1)
            return 9;
        vector<vector<int>> jump(10, vector<int>(10,0));
        jump[1][3] = 2;
        jump[3][1] = 2;
        jump[1][7] = 4;
        jump[7][1] = 4;
        jump[7][9] = 8;
        jump[9][7] = 8;
        jump[9][3] = 6;
        jump[3][9] = 6;
        jump[2][8] = 5;
        jump[8][2] = 5;
        jump[4][6] = 5;
        jump[6][4] = 5;
        jump[1][9] = 5;
        jump[9][1] = 5;
        jump[3][7] = 5;
        jump[7][3] = 5;
        vector<bool> visited(10, false);
        int ret = 0;
        int len = 1;
        int methods = 0;
        dfs(1, jump, m, n, len, ret, visited);
        methods += ret*4;
        ret = 0;
        dfs(2, jump, m, n, len, ret, visited);
        methods += ret*4;
        ret = 0;
        dfs(5, jump, m, n, len, ret, visited);
        methods += ret;
        return methods;
    }
    
    void dfs(int num, vector<vector<int>>& jump, int m, int n, int len, int& ret, vector<bool>& visited)
    {
        if(len > n)
            return;
        if(len >= m)
            ++ret;
        len += 1;
        visited[num] = true;
        for(int next = 1; next <= 9; ++next)
        {
            int j = jump[num][next];
            if(visited[next])
                continue;
            if(j == 0 || visited[j] == true)
                dfs(next, jump, m, n, len, ret, visited);
        }
        visited[num] = false;
        return;
    }
};
