class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        if(groupSizes.size() == 0) {
            return {};
        }
        vector<vector<int>> ret;
        unordered_map<int, vector<vector<int>>> m;
        for(int i = 0; i < groupSizes.size(); ++i) {
            if(m.count(groupSizes[i]) == 0) {
                vector<int> v;
                v.push_back(i);
                m[groupSizes[i]].push_back(v);
            } else {
                if(m[groupSizes[i]].back().size() < groupSizes[i]) {
                    m[groupSizes[i]].back().push_back(i);
                } else {
                    vector<int> v;
                    v.push_back(i);
                    m[groupSizes[i]].push_back(v);
                }
            }
        }
        for(auto entry: m) {
            for(auto vec: entry.second) {
                ret.push_back(vec);
            }
        }
        return ret;
    }
};
