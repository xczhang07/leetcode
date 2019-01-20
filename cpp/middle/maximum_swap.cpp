class Solution {
public:
    int maximumSwap(int num) {
        string str_num = to_string(num);
        if(str_num.size() == 1)
            return num;
        int new_num = 0;
        string swapped;
        for(int i = 0; i < str_num.size()-1; ++i)
        {
            for(int j = i+1; j < str_num.size(); ++j)
            {
                swapped = str_num;
                swapped[i] = str_num[j];
                swapped[j] = str_num[i];
                new_num = stoi(swapped);
                if(new_num > num)
                    num = new_num;
            }
        }
        return num;
    }
};


Conclusion:
brute force解法，针对每一个数字，和其他位互换，比较两个数字的值。
time complexity: O(n^2)
space complexity: O(1)

    
Solution #2

Time Complexity is: O(n)
Space Complexity is: O(1)
analysis:
we need to swap the largest value in the lowest position to the smallest value in the highest position
thus, the following method do this way.

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

