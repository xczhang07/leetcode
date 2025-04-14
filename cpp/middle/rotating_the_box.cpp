class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        if(boxGrid.size() == 0 || boxGrid[0].size() == 0) {
            return boxGrid;
        }
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> rotateBox(n, vector<char>(m,'.'));
        // rotate the 90 degree of the input box.
        int c = 0;
        int nr = 0;
        while(c < n) {
            int r = m-1;
            int nc = 0;
            while(r >= 0) {
                int original = boxGrid[r][c];
                rotateBox[nr][nc] = original;
                r -= 1;
                nc += 1;
            }
            nr += 1;
            c += 1;
        }
        c = 0;
        while(c < m) {
            int l = n-1;
            int r = n-1;
            while(l >= 0) {
                if(rotateBox[l][c] == '.') {
                    l -= 1;
                } else if(rotateBox[l][c] == '#') {
                    if(rotateBox[r][c] == '.') {
                        swap(rotateBox[l][c], rotateBox[r][c]);
                    }
                    l -= 1;
                    r -= 1;
                } else {
                    l -= 1;
                    r = l;
                }
            }
            c += 1;
        }
        return rotateBox;
    }
};
