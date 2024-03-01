class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.size() == 0 || mat[0].size() == 0) {
            return {};
        }
        vector<int> ret;
        int n = mat.size();
        int m = mat[0].size();
        int r = 0, c = 0;
        bool goUp = true;
        while(r < n && c < m) {
            if(goUp) {
                while(r > 0 && c < m-1) {
                    ret.push_back(mat[r][c]);
                    r--;
                    c++;
                }
                ret.push_back(mat[r][c]);
                if(c == m-1) {
                    ++r;
                } else {
                    ++c;
                }
            } else { // go down of the diagonal
                while(r < n-1 && c > 0) {
                    ret.push_back(mat[r][c]);
                    ++r;
                    --c;
                }
                ret.push_back(mat[r][c]);
                if(r == n-1) {
                    ++c;
                } else {
                    ++r;
                }
            }
            goUp = !goUp;
        }
        return ret;
    }
};
