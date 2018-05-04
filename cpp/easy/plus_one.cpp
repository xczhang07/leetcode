class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret;
        int counter = 1;
        for(int i = digits.size()-1; i >= 0; --i)
        {
            int sum = digits[i] + counter;
            counter = sum/10;
            sum = sum % 10;
            ret.insert(ret.begin(), sum);
        }
        /* check whether or not the counter is 1 */
        if(counter == 1)
            ret.insert(ret.begin(), counter);
        return ret;
    }
};

Conclusion: process the input array from tail to head, then don't forget to add the 1 to the head of array

Time Complexity: O(n)
Space Complexity: O(n)
