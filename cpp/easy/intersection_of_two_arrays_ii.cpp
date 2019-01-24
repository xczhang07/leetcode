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

    
sorting array version, for follow up:

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.size() == 0 || nums2.size() == 0)
            return ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] < nums2[j])
                ++i;
            else if(nums1[i] > nums2[j])
                ++j;
            else
            {
                ret.push_back(nums1[i]);
                ++i;
                ++j;
            }
        }
        return ret;
    }
};

time complexity is: O(m+n)

