class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ret;
        if(numbers.size() == 0)
            return ret;
        int start = 0;
        int end = numbers.size()-1;
        while(start < end)
        {
            int sum = numbers[start]+numbers[end];
            if(numbers[start]+numbers[end] == target)
            {
                ret.push_back(start+1);
                ret.push_back(end+1);
                return ret;
            }
            else if(sum > target)
                --end;
            else
                ++start;
        }
    }
};

Conclusion:
easy algorithm question, time complexity is O(n), space complexity is O(1)
