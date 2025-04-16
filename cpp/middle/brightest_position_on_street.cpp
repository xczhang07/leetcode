class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        if(lights.size() == 0) {
            return 0;
        }
        int tmpBright = 0, brightest = 0, pos = 0;
        vector<pair<int,int>> streetLine;
        for(auto& l : lights) {
            streetLine.push_back({l[0]-l[1], 1});
            streetLine.push_back({l[0]+l[1]+1, -1});
        }
        sort(streetLine.begin(), streetLine.end());
        for(auto& e: streetLine) {
            tmpBright += e.second;
            if(tmpBright > brightest) {
                brightest = tmpBright;
                pos = e.first;
            }
        }
        return pos;
    }
};
