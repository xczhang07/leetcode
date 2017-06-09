class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> miss_nums;
        vector<int> map(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); ++i)
            map[nums[i]]++;
        for(int i = 1; i < map.size(); ++i)
        {
            if(map[i] == 0)
                miss_nums.push_back(i);
        }
        return miss_nums;
    }
};


Conclusion:

easy! hash_table can solve this algorithm issue
time complexity: O(n)
space complexity: O(n)
