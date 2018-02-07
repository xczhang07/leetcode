class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ret = 0;
        for(int i = 0; i < points.size(); ++i)
        {
            unordered_map<long,int> group;
            for(int j = 0; j < points.size(); ++j)
            {
                if(i == j)
                    continue;
                int dx = points[i].first-points[j].first;
                int dy = points[i].second - points[j].second;
                int key = dx * dx;
                key += dy * dy;
                group[key]++;
            }
            
            for(auto& p : group)
            {
                if(p.second > 1)
                    ret += p.second*(p.second-1);
            }
        }
        return ret;
    }
};


Conclusion:
create a hash map, caculate the distance for each two points. the same distance number store in the hashmap. then if one distance value number is greater than
2, to caculate the combination is the formula: n*(n-1)

Time Complexity: O(n^2)
Space Complexity: O(n)
