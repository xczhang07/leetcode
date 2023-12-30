class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size())
            return -1;
        priority_queue<int> pq; // priority queue, if we push 8, 9, 5, 4, 10, the sequence of num should be: 10, 9 ,8, 5, 4
        for(auto num : nums)
            pq.push(num);
        while(k > 1)
        {
            k--;
            pq.pop();
        }
        return pq.top();
    }
};


Conclusion:
we can use priority queue to resolve this issue.

Time Complexity: O(n+klogn), every time, the pop operation of priority_queue is logn, and we need to perform this operation k times.
Space Complexity: O(n)

Solution 2:
Using quickselect to resolve this issue, the avg runtime is O(n) , the worst case is O(n^2); the avg runtime is better than the using heap solution.
Reference: https://www.interviewbit.com/blog/kth-largest-element-of-array/

class Solution {
public:
    int partition(vector<int>& nums, int k, int start, int end){
        if (start==end){
            return start;
        }
        int pivot = rand()%(end-start+1)+start;
        swap(nums[pivot], nums[end]);
        pivot = start;
        for (int i=start; i<end; i++){
            if (nums[i]<nums[end]){
                swap(nums[i], nums[pivot++]);
            }
        }
        swap(nums[pivot], nums[end]);
        return pivot;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int target = n-k;
        int start = 0;
        int end = n-1;
        int pivot=0;
        while (true){
            pivot = partition(nums, target, start, end);
            if (pivot==target){
                return nums[target];
            }
            int tmp = pivot;
            if (target>pivot){
                
                while (tmp<=target-2 && nums[tmp]==nums[tmp+1]){
                    tmp++;
                }
                start = tmp+1;
            } else{
                while (tmp>=target+2 && nums[tmp]==nums[tmp-1]){
                    tmp--;
                }
                end = tmp-1;
            }
        }
    }
};
