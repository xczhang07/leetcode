class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        if(img.size() == 0 || img[0].size() == 0) {
            return img;
        }
        int m = img.size();
        int n = img[0].size();
        int k = 256;
        vector<pair<int, int>> moveDirs = {{0,0}, {-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1, -1}, {-1, 1}, {1,1}};
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int sum = 0;
                int cnt = 0;
                for(auto dir : moveDirs) {
                    int x = i + dir.first;
                    int y = j + dir.second;
                    if(x >= 0 && x < m && y >= 0 && y < n) {
                        // get the img original value.
                        sum += img[x][y]%k;
                        cnt += 1;
                    }
                }
                // encode the smoothed value in img[i][j].
                img[i][j] += (sum/cnt)*k;
            }
        }
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                img[i][j]/=k;
            }
        }
        return img;
    }
};
