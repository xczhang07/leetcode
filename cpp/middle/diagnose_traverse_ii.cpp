O(m*k) solution
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ret;
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); ++i) {
            int row = i;
            for(int j = 0; j < nums[row].size(); ++j) {
                int col = j;
                m[row+col].push_back(nums[row][col]);
            }
        }
        for(auto& entry: m) {
            vector<int> level = entry.second;
            reverse(level.begin(), level.end());
            ret.insert(ret.end(), level.begin(), level.end());
        }
        return ret;
    }
};


O(m+k) solution
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        queue<pair<int,int>> idxQ;
        vector<int> ret;
        idxQ.push({0,0});
        while(!idxQ.empty()) {
            auto element = idxQ.front();
            idxQ.pop();
            int i = element.first;
            int j = element.second;
            ret.push_back(nums[i][j]);
            if(j == 0 && i + 1 < n) {
                idxQ.push({i+1, 0});
            }
            if(j+1 < nums[i].size()) {
                idxQ.push({i, j+1});
            }
        }
        return ret;
    }
};
