class Solution {
public:
    
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> char_map;
        char_map['q'] = 0;
        char_map['w'] = 0;
        char_map['e'] = 0;
        char_map['r'] = 0;
        char_map['t'] = 0;
        char_map['y'] = 0;
        char_map['u'] = 0;
        char_map['i'] = 0;
        char_map['o'] = 0;
        char_map['p'] = 0;
        char_map['a'] = 1;
        char_map['s'] = 1;
        char_map['d'] = 1;
        char_map['f'] = 1;
        char_map['g'] = 1;
        char_map['h'] = 1;
        char_map['j'] = 1;
        char_map['k'] = 1;
        char_map['l'] = 1;
        char_map['z'] = 2;
        char_map['x'] = 2;
        char_map['c'] = 2;
        char_map['v'] = 2;
        char_map['b'] = 2;
        char_map['n'] = 2;
        char_map['m'] = 2;
        vector<string> ret;
        int i, j = 0;
        if(words.size() == 0)
            return ret;
        for(i = 0; i < words.size(); ++i)
        {
            int row = 0;
            for(j = 0; j < words[i].size(); ++j)
            {
                char tmp = tolower(words[i][j]);
                if(j == 0)
                    row = char_map[tmp];
                else{
                    if(char_map[tmp] != row)
                        break;
                }
            }
            if(j == words[i].size())
                ret.push_back(words[i]);
        }
        return ret;
    }
};
