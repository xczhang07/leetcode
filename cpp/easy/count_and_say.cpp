class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        while(n > 1)
        {
            ret = read(ret);
            --n;
        }
        return ret;
    }
    
    string read(string str)
    {
        string ret;
        for(int i = 0; i < str.size(); ++i)
        {
            int count = 1;
            while(i < str.size()-1 && str[i] == str[i+1])
            {
                count += 1;
                ++i;
            }
            ret += to_string(count);
            ret += str[i];
        }
        return ret;
    }
};


Conclusion: an easy level algorithm issue, no comments.


Time Complexity: O(n)
Space Complexity: O(1)
