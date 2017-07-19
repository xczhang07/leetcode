class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        if(nums.size() == 0)
            return ret;
        int num1 = 0;
        int num2 = 0;
        int num1_count = 0;
        int num2_count = 0;
        for(auto a : nums) {
            if(a == num1)
                ++num1_count;
            else if(a == num2)
                ++num2_count;
            else if(num1_count == 0) {
                num1 = a;
                num1_count = 1;
            }
            else if(num2_count == 0) {
                num2 = a;
                num2_count = 1;
            }
            else {
                num1_count--;
                num2_count--;
            }
        }
        num1_count = 0;
        num2_count = 0;
        for(auto a : nums) {
            if(a == num1)
                ++num1_count;
            else if(a == num2)
                ++num2_count;
        }
        if(num1_count > nums.size()/3)
            ret.push_back(num1);
        if(num2_count > nums.size()/3)
            ret.push_back(num2);
        return ret;
    }
};



Conclusion:
Middle level algorithm issue. 
First of all, we need to know that there exists at most 2 numbers to match the requirements(math common knowledge).
Secondly, we iterate the whole array, then we are able to find out the those two numbers.
finally, we need to double check the apperance of those two number whether or not they are greater than n/3
eg [1,2,4,1,2,1,1,2,1]: only 1's apperance time is greater than 3 (1/3 of the whole array length)

Time Complexity: O(n)
Space Complexity: O(1)
