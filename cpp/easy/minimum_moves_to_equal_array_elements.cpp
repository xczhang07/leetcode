class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return 0;
        int mn = INT_MAX, res = 0;
        for (int num : nums) mn = min(mn, num);
        for (int num : nums) res += num - mn;
        return res;
    }
};

Conclusion:

the problem is equal as: find the minimum value in the array, caculate the distance from each element to the minimum value.
