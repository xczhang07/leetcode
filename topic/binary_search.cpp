Binary 3 templates:
template 1:
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size() - 1;
  while(left <= right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid - 1; }
  }

  // End Condition: left > right
  return -1;
}

template 2:
int binarySearch(vector<int>& nums, int target){
  if(nums.size() == 0)
    return -1;

  int left = 0, right = nums.size();
  while(left < right){
    // Prevent (left + right) overflow
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){ return mid; }
    else if(nums[mid] < target) { left = mid + 1; }
    else { right = mid; }
  }

  // Post-processing:
  // End Condition: left == right
  if(left != nums.size() && nums[left] == target) return left;
  return -1;
}

template 3:




1. Classical Binary Search
Find any position of a target number in a sorted array. Return -1 if target does not exist.

Example
Given [1, 2, 2, 4, 5, 5].

For target = 2, return 1 or 2.

For target = 5, return 4 or 5.

For target = 6, return -1.

Challenge
O(logn) time
class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        // write your code here
        if(nums.size() == 0)
            return -1;
        if(target < nums[0] || target > nums[nums.size()-1])
            return -1;
        int l = 0;
        int r = nums.size()-1;
        while(l <= r)
        {
            int m = l + (r-l)/2;
            if(nums[m] == target)
                return m;
            else if(nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        
        return -1;
    }
};


2. First Position of Target
For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge
If the count of numbers is bigger than 2^32, can your code work properly?

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        if(nums.size() == 0)
            return -1;
        if(target < nums[0] || target > nums[nums.size()-1])
            return -1;
        int i = 0;
        int j = nums.size()-1;
        while(i <= j)
        {
            int m = (i+j) >> 1;
            if(nums[m] == target)
            {
                if(m > 0 && nums[m-1] == target)
                    j = m-1;
                else
                    return m;
            }
            else if(nums[m] < target)
                i = m+1;
            else
                j = m-1;
        }
        return -1;
    }
};

3. Last Position of Target
Find the last position of a target number in a sorted array. Return -1 if target does not exist.

Example
Given [1, 2, 2, 4, 5, 5].

For target = 2, return 2.

For target = 5, return 5.

For target = 6, return -1.

class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int lastPosition(vector<int> &nums, int target) {
        // write your code here
        if(nums.size() == 0)
            return -1;
        else if(target < nums[0] || target > nums[nums.size()-1])
            return -1;
        int i = 0;
        int j = nums.size()-1;
        while(i <= j)
        {
            int m = (i+j) >> 1;
            if(nums[m] == target)
            {
                if(m < nums.size()-1 && nums[m+1] == target)
                    i = m+1;
                else
                    return m;
            }
            else if(nums[m] < target)
                i = m+1;
            else
                j = m-1;
        }
        return -1;
    }
};


4. Search in a Big Sorted Array
Given a big sorted array with positive integers sorted by ascending order. The array is so big so that you can not get the length of the whole array directly, and you can only access the kth number by ArrayReader.get(k) (or ArrayReader->get(k) for C++). Find the first index of a target number. Your algorithm should be in O(log k), where k is the first index of the target number.

Return -1, if the number doesn't exist in the array.

Example
Given [1, 3, 6, 9, 21, ...], and target = 3, return 1.

Given [1, 3, 6, 9, 21, ...], and target = 4, return -1.

Challenge
O(log k), k is the first index of the given target number.

class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        int right = 1;
        while(reader->get(right) < target)
            right *= 2;
        int left = 0;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(reader->get(mid) == target)
            {
                if(mid > 0 && reader->get(mid-1) == target)
                    right = mid-1;
                else
                    return mid;
            }
            else if(reader->get(mid) < target)
                left = mid + 1;
            else
                right = mid-1;
        }
        if(reader->get(left) == target)
            return left;
        else if(reader->get(right) == target)
            return right;
        else
            return -1;
    }
};
