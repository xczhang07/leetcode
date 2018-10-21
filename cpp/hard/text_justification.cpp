class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        int i = 0;
        while(i < words.size())
        {
            int j = i;
            int len = 0;
            /* caculate each length , j-i => space number*/
            while(j < words.size() && len + words[j].size() + j - i <= maxWidth)
            {
                len += words[j].size();
                ++j;
            }
            string line;
            int space_num = maxWidth - len;
            
            for(int k = i; k < j; ++k)
            {
                line += words[k];
                if(space_num > 0)
                {
                    int tmp = 0;
                    if(j == words.size())
                    {
                        if(j - k == 1)
                            tmp = space_num;
                        else
                            tmp = 1;
                    }
                    else
                    {
                        if(j - k - 1 > 0)
                        {
                            if(space_num % (j-k-1) == 0)
                                tmp = space_num / (j-k-1);
                            else
                                tmp = space_num / (j-k-1) + 1;
                        }
                        else
                            tmp = space_num;
                    }
                    line.append(tmp, ' ');
                    space_num -= tmp;
                }
            }
            
            ret.push_back(line);
            i = j;
        }
        return ret;
    }
};

/*
a hard level algorithm issue, need to redo it.
*/
