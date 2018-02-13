class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> ret;
        for(int num:nums1)
            map[num]++;
        for(int num:nums2)
        {
            if(map[num] > 0)
            {
                ret.push_back(num);
                map[num]--;
            }
        }
        return ret;
    }
};

Conclusion: an easy algorithm issue, using hash_map can resolved this issue.

Time Complexity: O(m+n)
Space Complexity: O(n)


