class Solution {
public:
    string shift(string s) {
        string key = "";
        for(int i = 1; i < s.size(); ++i) {
            int dist = s[i] - s[i-1];
            if(dist < 0) {
                dist += 26;
            }
            key = key + to_string(dist) + "a"+".";
        }
        return key;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ret;
        if(strings.size() == 0) {
            return ret;
        }
        unordered_map<string, vector<string>> m;
        for(auto str: strings) {
            m[shift(str)].push_back(str);
        }
        for(auto entry: m) {
            ret.push_back(entry.second);
        }
        return ret;
    }
};
