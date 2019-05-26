class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        if(words.size() == 0)
            return ret;
        int i = 0;
        while(i < words.size())
        {
            int j = i;
            int len = 0;
            while(j < words.size() && len + words[j].size() + j-i <= maxWidth)
            {
                len += words[j].size();
                ++j;
            }
            string line;
            int spaces = maxWidth-len;
            for(int k = i; k < j; ++k)
            {
                line += words[k];
                int tmp = 0;
                if(spaces > 0)
                {
                    if(j == words.size())
                    {
                        if(j-k == 1)
                            tmp = spaces;
                        else
                            tmp = 1;
                    }
                    else
                    {
                        if(j-k > 1)
                        {
                            if(spaces%(j-k-1) == 0)
                                tmp = spaces/(j-k-1);
                            else
                                tmp = spaces/(j-k-1)+1;
                        }
                        else
                            tmp = spaces;
                    }
                    spaces -= tmp;
                    line.append(tmp, ' ');
                }
            }
            ret.push_back(line);
            i = j;
        }
        return ret;
    }
};
