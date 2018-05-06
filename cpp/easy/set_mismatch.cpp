class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        if(nums.size() <= 1)
            return ret;
        vector<int> map(n+1, 0);
        for(int i = 0; i < nums.size(); ++i)
        {
            if(map[nums[i]] != 0)
                ret.push_back(nums[i]);
            else
                map[nums[i]] += 1;
        }
        for(int i = 1; i <=n; ++i)
        {
            if(map[i] == 0)
                ret.push_back(i);
        }
        return ret;
    }
};




Conclusion:
Easy algorithm issue.
Time Complexity: O(n)
Space Complexity: O(n)


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i)
        {
            while(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1)
                return {nums[i], i+1};
        }
    }
};

Conclusion:
space O(1) solution: map the number from 1 to n to the array for the index i+1, when we found out nums[i] != i+1
then, the result is: [nums[i], i+1]
Time complexity: O(n)
Space Complexity: O(1) 
