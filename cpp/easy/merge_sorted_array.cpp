class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* invalidation check */
        if(nums1.size() == 0) return;
        if(nums2.size() == 0) return;
        int idx1 = m-1;
        int idx2 = n-1;
        int len = m+n-1;
        while(idx1 >= 0 && idx2 >= 0)
        {
            if(nums1[idx1] >= nums2[idx2])
            {
                nums1[len] = nums1[idx1];
                --len;
                --idx1;
            }
            else
            {
                nums1[len] = nums2[idx2];
                --len;
                --idx2;
            }
        }
        while(idx1 >= 0)
        {
            nums1[len] = nums1[idx1];
            --len;
            --idx1;
        }
        while(idx2 >= 0)
        {
            nums1[len] = nums2[idx2];
            --len;
            --idx2;
        }
        return;
    }
};


Conclusion: an easy algorithm issue, we need to consider the given condition (nums1 has the enough space to hold elements from nums and nums2).
Thus, we start to merge the array from end of both array.

Time Complexity: O(m+n)
Space Complexity: O(1)
