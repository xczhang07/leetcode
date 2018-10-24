class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num : nums)
            sum += num;
        if(sum % 2 == 1)
            return false;
        int target = sum / 2;
        unordered_set<int> s;
        s.insert(target);
        for(int num : nums)
        {
            if(s.find(num) != s.end())
                return true;
            else
            {
                for(auto ele : s)
                {
                    if(ele > num)
                        s.insert(ele - num);
                }
            }
        }
        return false;
    }
};

/*
Conclusion:
an middle level algorithm issue.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
