class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> my_set;
        vector<int> ret;
        for(int num : nums1)
            my_set.insert(num);
        for(int num : nums2)
        {
            if(my_set.count(num) > 0)
            {
                ret.push_back(num);
                my_set.erase(num);
            }
        }
        return ret;
    }
};


Conclusion:
easy algorithm issue, unordered set can solve this issue.


Time Complexity: O(m+n)
Space Complexity: O(n)
