class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // binary search
        int start = 0;
        int end = nums.size()-1;
        int mid = 0;
        while(start < end)
        {
            mid = start + (end-start)/2;
            // if mid is even
            if(mid%2 == 0)
            {
                if(nums[mid] == nums[mid+1])
                    start = mid+2;
                else if(nums[mid-1] == nums[mid])
                    end = mid-2;
                else
                    return nums[mid];
            }
            else
            {
                // if mid is odd
                if(nums[mid] == nums[mid+1])
                    end = mid-1;
                else if(nums[mid] == nums[mid-1])
                    start = mid+1;
                else
                    return nums[mid];
            }
        }
        return nums[start];
    }
};

Conclusion:
a middle level algorithm issue, according to the requirments, we need to use O(lgn) time complexity and O(1) space complexity to solve
this it; thus, binary search is the best choice for this issue! Oberserve this issue, for eg:
[1, 1, 2, 2, 3, 5, 5, 7, 7]
 0  1  2  3  4  5  6  7  8
the duplicate nums on the left of target number, the first's index is even (can be divided by 2), the 2nd's index is odd(can't be divided by
2), the nums on the right of target number, the first's index is odd, and the 2nd index is even, thus, our solution as following:
1. define the start position is 0; the end position is the last index of the array nums.size()-1
2. then calculate the mid = start + (end-start)/2
3. if the mid is even and nums[mid] == nums[mid+1], which means the target number is on the right of nums[mid+1]
4. if the mid is even and nums[mid] == nums[mid-1], which means the target number is on the left of nums[mid-1]
5. if the mid is odd and nums[mid] == nums[mid+1], which means the target number is on the left of nums[mid]
6. if the mid is odd and nums[mid] == nums[mid-1], which means the target number is on the right of nums[mid]

Time Complexity is: O(logn)
Space Complexity is: O(1)
