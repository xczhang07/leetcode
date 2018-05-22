class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> my_set;
        int ret = 0;
        int len = nums.size();
        for(int i = 0; i < len-1; ++i)
        {
            for(int j = i + 1; j < len; ++j)
            {
                if(abs(nums[i]-nums[j]) == k)
                {
                    if(my_set.find(nums[i]+nums[j]) == my_set.end())
                    {
                        my_set.insert(nums[i]+nums[j]);
                        ++ret;
                    }
                }
            }
        }
        return ret;
    }
};


Conclusion: an easy algorithm level issue. using set to store the sum of two numbers which staisfy the requirments(also avoid the duplicate answer)

Time Complexity: O(n^2)
Space Complexity: O(n)

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        unordered_set<int> s1;
        set<pair<int,int>> pairs;
        for(int num : nums)
        {
            if(s1.find(num+k) != s1.end())
                pairs.insert({num, num+k});
            if(s1.find(num-k) != s1.end())
                pairs.insert({num-k, num});
            s1.insert(num);
        }
        return pairs.size();
    }
};

Conclusion: we use two sets to resolve this issue. a good method to practice.

Time Complexity: O(n)
Space Complexity: O(n)
