class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
       int left = 0, right = nums.size()-1;
       int window = nums[0]-1;
       while(left <= right) {
           int mid = left + (right-left)/2;
           int missing_num = nums[mid]-(mid+1);
           if(missing_num < k + window) {
               left = mid + 1;
           } else {
               right = mid - 1;
           }
       }
       return left + k + window;
    }
};
