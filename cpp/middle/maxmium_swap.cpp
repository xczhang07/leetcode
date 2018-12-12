class Solution {
public:
    int maximumSwap(int num) {
        if(num <= 0) return 0;
        string str = to_string(num);
        int max_num = num;
        string tmp_str;
        for(int i = 0; i < str.size()-1; ++i)
        {
            char tmp = str[i];
            for(int j = i+1; j < str.size(); ++j)
            {
                if(str[j] >= tmp)
                {
                    tmp_str = str;
                    tmp = str[j];
                    tmp_str[j] = str[i];
                    tmp_str[i] = tmp;
                    if(stoi(tmp_str) > max_num)
                        max_num = stoi(tmp_str);
                }
            }
        }
        return max_num;
    }
};

Time Complexity is: O(n^2)
