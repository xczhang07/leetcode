class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        if(regions.size() == 0 || region1.size() == 0 || region2.size() == 0) {
            return "";
        }
        unordered_map<string, string> parents;
        for(vector<string>& region: regions) {
            string parent = region[0];
            for(int i = 1; i < region.size(); ++i) {
                parents[region[i]] = parent;
            }
        }
        string x = region1;
        string y = region2;
        while(x != y) {
            if(parents.find(x) != parents.end()) {
                x = parents[x];
            } else {
                x = region2;
            }
            if(parents.find(y) != parents.end()) {
                y = parents[y];
            } else {
                y = region1;
            }
        }
        return x;
    }
};
