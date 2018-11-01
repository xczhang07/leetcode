class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) 
            return s;
        vector<string> z(numRows, "");
        int row = 0;
        int direction = -1;
        string ret;
        for(int i = 0; i < s.size(); ++i)
        {
            z[row].push_back(s[i]);
            if(row == 0 || row == numRows-1)
                direction *= -1;
            row += direction;
        }
        for(auto x: z)
            ret.append(x);
        return ret;
    }
};


/*
a middle level algorithm issue, we need to discover the rules how to convert the input string to zigzag. a good article as following:
https://buptwc.github.io/2018/10/12/Leetcode-6-ZigZag-Conversion/
*/
