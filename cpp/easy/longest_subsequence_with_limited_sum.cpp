class Solution {
public:

    // Search the upper_bound index of a number in a sorted array
    int binarySearch(vector<int>& arr, int& target) {
        int l = 0, r = arr.size()-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(target > arr[m]) {
                l = m + 1;
            } else if (target == arr[m]) {
                return m+1;
            }else {
                r = m - 1;
            }
        }
        return l; // upper bound
    }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        if(nums.size() == 0 || queries.size() == 0) {
            return {};
        }
        sort(nums.begin(), nums.end());
        // Create the prefix sum array.
        for(int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
        }
        vector<int> ret;
        for(auto& query : queries) {
            // Using binarySearch to find each query's upper_bound in the prefix sum array.
            ret.push_back(binarySearch(nums, query));
        }
        return ret;
    }
};

Time Complexity is: O(nlogn)<---sorting + O(n) <---creating prefix sum + O(mlgn) search m elements in n size array with binary search
Space Complexity is: O(1)
