class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<bool> visited(nums.size(), false);
        vector<int> temp;
        sort(nums.begin(), nums.end());
        dfs(ret, nums, temp, visited);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int>& nums, vector<int>& temp, vector<bool>& visited)
    {
        if(temp.size() == nums.size())
        {
            ret.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!visited[i])
            {
                temp.push_back(nums[i]);
                visited[i] = true;
                dfs(ret, nums, temp, visited);
                visited[i] = false;
                temp.pop_back();
                while(i+1 < nums.size() && nums[i] == nums[i+1])
                    ++i;
            }
           
        }
        return;
    }
};

/*
Conclusion:
an middle level algorithm issue, very similar with permutation question. we can use dfs to resolve this issue, do not forget to sort the input list and to the cutting if two elements is the same.
*/
