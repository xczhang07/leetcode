class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size() == 0) {
            return {};
        }
        vector<int> ret;
        // Convert the input string to the vector window.
        unordered_map<char, vector<int>> m;
        for(int i = 0; i < s.size(); ++i) {
            if(m.find(s[i]) != m.end()) {
                if(m[s[i]].size() < 2) {
                    m[s[i]].push_back(i);
                } else {
                    if(i > m[s[i]][1]) {
                        m[s[i]][1] = i;
                    }
                }
            } else {
                m[s[i]].push_back(i);
            }
        }
        vector<vector<int>> pos;
        for(auto iter = m.begin(); iter != m.end(); ++iter) {
            if(iter->second.size() == 1) {
                iter->second.push_back(iter->second[0]);
            }
            pos.push_back(iter->second);
        }
        sort(pos.begin(), pos.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int start = 0;
        int end = pos[0][1];
        for(int i = 1; i < pos.size(); ++i) {
            if(pos[i][0] < end) {
                start = min(start, pos[i][0]);
                end = max(end, pos[i][1]);
            } else {
                ret.push_back(end-start+1);
                start = pos[i][0];
                end = pos[i][1];
            }
        }
        ret.push_back(end-start+1);
        return ret;
    }
};
