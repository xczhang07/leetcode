class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int ret = 0;
        for(int num : nums)
        {
            if(!s.count(num))
                continue;
            int pre = num;
            int next = num;
            s.erase(num);
            while(s.count(pre-1))
                pre--;
            while(s.count(next+1))
                next++;
            ret = max(ret, next-pre+1);
        }
        return ret;
    }
};
