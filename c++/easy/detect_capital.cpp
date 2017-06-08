class Solution {
public:
    bool detectCapitalUse(string word) {
        string temp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int pos = 0;
        int capital_cnt = 0;
        for(int i = 0; i < word.size(); ++i)
        {
            int is_in =temp.find(word[i]);
            if(is_in != -1)
            {
                ++capital_cnt;
                pos = i;
            }
        }
        if(capital_cnt == 0)
            return true;
        else if(capital_cnt == word.size())
            return true;
        else if(capital_cnt == 1 && pos == 0)
            return true;
        else
            return false;
    }
};

Conclustion:
create a template string (from 'A' to 'Z') and to check whether or not each charactor in the template string.
time complexity O(n)
space complexity O(1)
