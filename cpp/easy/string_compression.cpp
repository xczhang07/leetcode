class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() <= 1) /* corner case check, input invalidation check */
            return chars.size();
        int cnt = 1;
        int len = 0;
        char curr = chars[0];
        chars.push_back('0'); // insert this charactor into the end of chars for the last charactor caculation.
        for(int i = 1; i < chars.size(); ++i)
        {
            if(chars[i] == curr)
                ++cnt;
            else
            {
                if(cnt > 1) {
                    string count = to_string(cnt);
                    for(auto c : count)
                    {
                        ++len;
                        chars[len] = c;
                    }
                } 
                chars[++len] = chars[i]; // update the charactor value with the current ith index value
                curr = chars[i];
                cnt = 1;
            }
        }
        return len;
    }
};


Conclusion: an easy level algorithm issue; however, this one requries some thinking does not belongs to easy level algorithm issue. 
1. for line number 9, we need to push back '0' in case of for the last charactor caculation.
2. for line 24, after update the element occurance number of the input array, we need to update the next element with
the current ith index value.


