class Solution {
public:
    void reverseWords(vector<char>& str) {
        if(str.size() == 0) return;
        reverse(str, 0, str.size()-1);
        int start = 0;
        int travel = 0;
        while(travel < str.size())
        {
            if(str[travel] != ' ')
                ++travel;
            else
            {
                reverse(str, start, travel-1);
                start = travel+1;
                travel++;
            }
        }
        reverse(str, start, travel-1);
        return;
    }
    
    void reverse(vector<char>& str, int i, int j)
    {
        while(i < j)
        {
           
            char tmp = str[i];
            str[i] = str[j];
            str[j] = tmp;
            ++i;
            --j;
        }
        return;
    }
};
