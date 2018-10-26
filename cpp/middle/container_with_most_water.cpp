class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max_water = 0;
        while(i < j)
        {
            int water = min(height[i], height[j]) * (j-i);
            max_water = max(water, max_water);
            if(height[i] < height[j])
                ++i;
            else
                --j;
        }
        return max_water;
    }
};

/*
a middle level algorithm issue. using two pointer can resolve the issue.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
