Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]


Time Complexity is: O(n)
Space Complexity is: O(1)

class Solution {
public:
    int maximumSwap(int num) {
        if(num < 10)
            return num;
        string num_str = to_string(num);
        int max_val = -1;
        int max_idx = -1, left_idx = -1, right_idx = -1;
        for(int i = num_str.size()-1; i >= 0; --i)
        {
            if(num_str[i] > max_val)
            {
                max_val = num_str[i];
                max_idx = i;
            }
            if(num_str[i] < max_val)
            {
                left_idx = i;
                right_idx = max_idx;
            }
        }
        if(left_idx == -1)
            return num;
        swap(num_str[left_idx], num_str[right_idx]);
        return stoi(num_str);
    }
};

