class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        map<char, int> window;
        map<string, int> count;
        int j = 0;
        int ret = 0;
        for(int i = 0; i < s.size(); ++i) {
            window[s[i]]++;
            while(window.size() > maxLetters || i-j+1 > maxSize) {
                window[s[j]]--;
                if(window[s[j]] == 0) {
                    window.erase(s[j]);
                }
                ++j;
            }
            while(i-j+1 >= minSize) {
                string subStr = "";
                subStr = s.substr(j, i-j+1);
                window[s[j]]--;
                if(window[s[j]] == 0) {
                    window.erase(s[j]);
                }
                j++;
                count[subStr]++;
            }
        }
        for(auto& iter: count) {
            ret = max(ret, iter.second);
        }
        return ret;
    }
};
