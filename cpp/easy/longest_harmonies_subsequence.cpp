class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        int ret = 0;
        map<int,int> my_map;
        for(int num:nums)
            my_map[num]++;
        for(auto ins:my_map)
        {
            if(my_map.count(ins.first+1))
                ret = max(ret, my_map[ins.first]+my_map[ins.first+1]);
        }
        return ret;
    }
};


Conclusion:
an easy algorithm issue.
because the question only require us to get the length of the subsequence (not to get the subsequence itself), in this case, we can use map
to caculate each element's frequence, then find out two elements which diff is 1, but the the sum of their frequence is the max.
at here we use map because of map has the sort functionality inside itself.

Time Complexity: O(n)
Space Complexity: O(n)
