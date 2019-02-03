Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Note:

Each element in the result must be unique.
The result can be in any order.

binary search solution:

Time Complexity is: O(nlogn)
Space Complexity is: O(n)


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.size() == 0 || nums2.size() == 0)
            return ret;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size(); ++i)
        {
            if(i > 0 && nums1[i] == nums1[i-1])
                continue;
            else
            {
                if(binary_search(nums2, nums1[i]) != -1)
                    ret.push_back(nums1[i]);
            }
        }
        
        return ret;
    }
    
    int binary_search(vector<int>& arr, int num)
    {
        if(arr.size() == 0)
            return -1;
        int i = 0, j = arr.size()-1;
        while(i <= j)
        {
            int m = i + (j-i)/2;
            if(arr[m] == num)
                return m;
            else if(arr[m] < num)
                i = m + 1;
            else
                j = m - 1;
        }
        return -1;
    }
};


hash set solution:
time complexity is: O(n)
space complexity is: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if(nums1.size() == 0 || nums2.size() == 0)
            return ret;
        unordered_set<int> s;
        for(int num : nums1)
            s.insert(num);
        for(int num : nums2)
        {
            if(s.count(num))
            {
                ret.push_back(num);
                s.erase(num);
            }
        }
        
        return ret;
    }
};
