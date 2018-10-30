class Solution {
public:
    int pathSum(vector<int>& nums) {
        map<pair<int,int>, int> mp;
        for(auto num : nums)
        {
            int v = num%10;
            num /= 10;
            int row = num/10;
            int col = num % 10;
            mp[make_pair(row, col)] = v;
        }
        int cur_sum = 0;
        int path_sum = 0;
        dfs(1, 1, cur_sum, path_sum, mp);
        return path_sum;
    }
    
    void dfs(int r, int c, int cur_sum, int& path_sum, map<pair<int,int>, int>& mp)
    {
        cur_sum += mp[{r,c}];
        if(mp.find({r+1, 2*c-1}) == mp.end() && mp.find({r+1, 2*c}) == mp.end())
        {
            path_sum += cur_sum;
            return;
        }
        if(mp.find({r+1, 2*c-1}) != mp.end())
            dfs(r+1, 2*c-1, cur_sum, path_sum, mp);
        if(mp.find({r+1, 2*c}) != mp.end())
            dfs(r+1, 2*c, cur_sum, path_sum, mp);
        return;
    }
};

/*
a middle level algorithm issue, according to the input array, convert it to a tree with the map.
then dfs the map according to its index, the for one node, its position is: (i,j), then its left child's index is: (i+1, 2j-1)
its right child's index is: (i+1, 2*j)

Time Complexity is: O(n)
Space Complexity is: O(n)
*/
