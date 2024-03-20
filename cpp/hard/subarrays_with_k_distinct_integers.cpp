class Solution {
public:
// Time complexity is: O(n)
// Space complexity is: O(k)
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }

    int atMost(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        int num = 0;
        int unique = 0;
        unordered_map<int, int> window;
        while(j < nums.size()) {
            if(window.find(nums[j]) == window.end()) {
                ++unique;
            }
            window[nums[j]]++;
            while(unique > k) {
                window[nums[i]]--;
                if(window[nums[i]] == 0) {
                    --unique;
                    window.erase(nums[i]);
                }
                ++i;
            }
            num += j-i+1;
            ++j;
        }
        return num;
    }
};

The explanation of why exactlyKdistinctelements = atMost(k) - atMost(k-1) as following:
https://leetcode.com/problems/subarrays-with-k-different-integers/solutions/523136/java-c-python-sliding-window
