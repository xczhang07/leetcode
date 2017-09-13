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
