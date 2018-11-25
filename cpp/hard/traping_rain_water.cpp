class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 1)
            return 0;
        int water = 0;
        int l = 0;
        int r = height.size()-1;
        while(l < r)
        {
            int mn = min(height[l], height[r]);
            if(mn == height[l])
            {
                ++l;
                while(l < r && height[l] < mn)
                {
                    water += (mn-height[l]);
                    ++l;
                }
            }
            else
            {
                --r;
                while(l < r && height[r] < mn)
                {
                    water += (mn-height[r]);
                    --r;
                }
            }
        }
        return water;
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
