class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ret(findNums.size(), 0);
        unordered_map<int, int> my_map;
        for(int i = 0; i < nums.size(); ++i)
            my_map[nums[i]] = i;
        for(int i = 0; i < findNums.size(); ++i)
        {
            ret[i] = -1;
            int pos = my_map[findNums[i]];
            for(int j = pos+1; j < nums.size(); ++j)
            {
                if(nums[j] > findNums[i])
                {
                    ret[i] = nums[j];
                    break;
                }
            }
        }
        return ret;
    }
};

Conclustion:
we use hash table in this algorithm issue, first of all, we stores the map between index and value in one map.
Then we iterater the subset array, find the position of the number, then find the next greater number in the large array.
