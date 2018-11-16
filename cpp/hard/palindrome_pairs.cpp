class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        unordered_map<string, int> m; // stores the reverse string of each word in words and its index
        for(int i = 0; i < words.size(); ++i)
        {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            m[tmp] = i;
        }
        
         if(m.find("")!=m.end()){
             for(int i = 0; i < words.size(); i++){
                 if(i == m[""]) continue;
                 if(isPalindrome(words[i])) 
                     ret.push_back({m[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self) 
             }
         }
        
        for(int i = 0; i < words.size(); ++i)
        {
            for(int j = 0; j < words[i].size(); ++j)
            {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size()-j);
                if(m.find(left) != m.end() && isPalindrome(right) && m[left] != i)
                    ret.push_back({i, m[left]});
                if(m.find(right) != m.end() && isPalindrome(left) && m[right] != i)
                    ret.push_back({m[right], i});
            }
        }
        return ret;
    }
    
    bool isPalindrome(string str)
    {
        if(str.size() <= 1)
            return true;
        int i = 0;
        int j = str.size()-1;
        while(i < j)
        {
            if(str[i] == str[j])
            {
                ++i;
                --j;
            }
            else
                return false;
        }
        return true;
    }
};
