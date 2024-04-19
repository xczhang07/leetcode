class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> freqSt;
        string ret;
        for(char c: s) {
            if(freqSt.empty()) {
                freqSt.push({c,1});
            } else {
                if(freqSt.top().first != c) {
                    freqSt.push({c, 1});
                } else {
                    int cnt = 1;
                    while(!freqSt.empty() && freqSt.top().first == c) {
                        cnt += freqSt.top().second;
                        freqSt.pop();
                    }
                    if(cnt < k) {
                        freqSt.push({c, cnt});
                    }
                }
            }
        }
        while(!freqSt.empty()) {
            ret.append(freqSt.top().second, freqSt.top().first);
            freqSt.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
