class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        if(A.size() <= 1)
            return A;
        vector<int> ret;
        for(int i = 0; i < A.size(); ++i)
        {
            if(A[i]%2 == 0)
                ret.insert(ret.begin(), A[i]);
            else
                ret.push_back(A[i]);
        }
        return ret;
    }
};

/*
easy algorithm issue.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size() <= 1) {
            return nums;
        }
        int even_idx = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i]%2 == 0) {
                int tmp = nums[i];
                nums[i] = nums[even_idx];
                nums[even_idx] = tmp;
                ++even_idx;
            }
        }
        return nums;
    }
};

Time Complexity: O(n)
Space Complexity: O(1)
