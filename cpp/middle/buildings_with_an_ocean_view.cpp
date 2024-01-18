class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        if(heights.empty()) {
            return ans;
        }
        int max_height = heights[heights.size()-1];
        ans.push_back(heights.size()-1);
        for(int i = heights.size()-2; i >= 0; --i) {
            if(heights[i] > max_height) {
                max_height = heights[i];
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
