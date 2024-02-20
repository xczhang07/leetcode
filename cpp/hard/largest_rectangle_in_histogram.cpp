class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0); // add a dummy node.
        stack<int> s; // store the index of the height array.
        int n = height.size();
        int i = 0;
        int max_area = 0;
        while(i < n) {
            if(s.empty()||height[i] >= height[s.top()]) {
                s.push(i);
                ++i;
            } else {
                int h = height[s.top()];
                s.pop();
                int w = s.empty()?i:i-1-s.top();
                max_area = max(max_area, h*w);
            }
        }
        return max_area;
    }
};
