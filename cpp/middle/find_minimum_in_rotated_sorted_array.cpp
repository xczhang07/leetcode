class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        int begin = 0;
        int end = nums.size()-1;
        while(begin < end)
        {
            if(nums[begin] < nums[end])
                return nums[begin];
            int mid = begin + (end-begin)/2;
            if(nums[begin] <= nums[mid])
                begin = mid+1;
            else
                end = mid;
        }
        return nums[begin] > nums[end]?nums[end]:nums[begin];
    }
};


Conclusion:
给一个被rotated 排序过的数组， 要求写程序找出这个数组中最小的元素。


典型的二分查找，分析如下：
corner case: 如果这个数组的长度为0，则我们要返回0；如果这个数组的长度为1， 则返回数组的第一个元素。
定义一个start position 0和end position nums.size()-1。while loop中start < end, 首先要检测是否 nums[start] < nums[end].
如果nums[start] < nums[end], 则直接返回nums[start]. 如果不是的话，说明，在区间[start,end], rotate存在于这段区间，于是我们缩小范围查找。
计算中位值 mid = start + (end-start)/2; 
如果nums[begin] <= nums[mid] => 在区间 [begin, mid] 还是排序区间的，则最小值肯定不在这个区间。所以我们要把 start = mid + 1
如果nums[begin] > nums[mid] => rotate 的位置在区间 [begin, mid] 中，所以我们要包含mid，把end放置于mid点。

Time Complexity: O(logn)
Space Complexity: O(1)
    
    
    
class Solution {
public:
    int findMin(vector<int>& nums) {
       int start = 0;
       int end = nums.size()-1;
        while(start <= end)
        {
            if(nums[start] <= nums[end])
                return nums[start];
            int mid = start + (end - start)/2;
            if(nums[start] <= nums[mid])
                start = mid + 1;
            else
                end = mid;
        }
        return min(nums[start], nums[end]);
    }
};
