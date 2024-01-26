class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()) {
            return 0;
        }
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int arrow = 1;
        int start = points[0][1];
        for(int i = 1; i < points.size(); ++i) {
            if(points[i][0] <= start) {
                continue;
            } else {
                ++arrow;
                start = points[i][1];
            }
        }
        return arrow;
    }
};

Time Complexity is: O(n)
Space Complexity is: O(1)
