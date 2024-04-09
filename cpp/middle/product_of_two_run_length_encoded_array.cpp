class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int i = 0, j = 0;
        vector<vector<int>> ret;
        while(i < encoded1.size() && j < encoded2.size()) {
           int freq = min(encoded1[i][1], encoded2[j][1]);
           int product = encoded1[i][0] * encoded2[j][0];
           encoded1[i][1] -= freq;
           encoded2[j][1] -= freq;
           if(ret.size() != 0 && ret.back()[0] == product) {
                ret.back()[1] += freq;
           } else {
                ret.push_back({product, freq});
           }
           if(encoded1[i][1] == 0) {
                ++i;
           }
           if(encoded2[j][1] == 0) {
                ++j;
           }
        }
        return ret;
    }
};
