class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1;
        int width = 0;
        vector<int> ret;
        for(char s : S)
        {
            width += widths[s-'a'];
            if(width >= 100)
            {
                lines++;
                if(width == 100)
                    width = 0;
                else
                    width = widths[s-'a'];
            }
        }
        ret.push_back(lines);
        ret.push_back(width);
        return ret;
    }
};

/*
wired question...
*/
