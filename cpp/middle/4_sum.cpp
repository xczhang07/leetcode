class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < int(nums.size()-3); ++i)
        {
            for(int j = i + 1; j < int(nums.size()-2); ++j)
            {
                if(j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int k = j + 1;
                int m = nums.size()-1;
                while(k < m)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[m];
                    if(sum == target)
                    {
                        vector<int> tmp{nums[i], nums[j], nums[k], nums[m]};
                        res.insert(tmp);
                        ++k;
                        --m;
                    }
                    else if(sum > target)
                        --m;
                    else
                        ++k;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};


/*
an middle level algorithm question.
Time Complexity is: O(n^3)
Space Complexity is: O(1)
Do not forget to convert unsigned integer (nums.size()-3) to signed integer.

*/
