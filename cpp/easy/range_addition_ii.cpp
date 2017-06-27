vclass Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0)
            return m*n;
        int raw_min = ops[0][0];
        int col_min = ops[0][1];
        for(int i = 0; i < ops.size(); ++i)
        {
            raw_min = min(raw_min, ops[i][0]);
            col_min = min(col_min, ops[i][1]);
        }
        return raw_min * col_min;
    }
};

Conclution:
Math issue, easy, no any other comments
