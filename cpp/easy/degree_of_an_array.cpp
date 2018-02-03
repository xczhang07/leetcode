class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        int degree = 0;
        int len = 0;
        unordered_map<int, int> element_index;  //a hash map to record each element start index
        unordered_map<int, int> element_freq;   //a hash map to record each element freq
        for(int i = 0; i < nums.size(); ++i)
        {
            if(element_index.find(nums[i]) == element_index.end())
                element_index[nums[i]] = i;
            element_freq[nums[i]]++;
            if(degree == element_freq[nums[i]])
                len = min(len, i - element_index[nums[i]] + 1);
            if(element_freq[nums[i]] > degree)
            {
                degree = element_freq[nums[i]];
                len = i - element_index[nums[i]] + 1;
            }
        }
        return len;
    }
};


Conclusion: a good algorithm issue, I like this one, use two hash map, one is used to track each element start index; another one is
used to record each element in the array's frequence. Update the frequence of each element on the fly, if one element's frequence is 
greater than the max degree, update the max degree value and caculate the len of contiguous subarray which contains the max degree.
if one subarray's degree equals to the max degree, just caculate the len to get the smaller one. 
Great thinking for this algorithm.

Time Complexity: O(n)
Space Complexity: O(n)
