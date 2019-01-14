class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        if(heights.size() == 0)
            return {};
        if(heights.size() == 1)
        {
            heights[K] += V;
            return heights;
        }
        while(V)
        {
            int pos = K;
            while(pos > 0 && heights[pos-1] <= heights[pos])
                --pos;
            while(pos < K && heights[pos] == heights[pos+1])
                ++pos;
            if(pos == K)
            {
                while(pos < heights.size()-1 && heights[pos+1] <= heights[pos])
                    ++pos;
                while(pos > K && heights[pos] == heights[pos-1])
                    --pos;
            }
            heights[pos]++;
            --V;
        }
        return heights;
    }
};

Time Complexity is: O(V*n)
Space Complexity is: O(1)
