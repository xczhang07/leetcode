class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows == 0)
            return ret;
        ret.push_back({1});
        if(numRows == 1)
            return ret;
        ret.push_back({1,1});
        if(numRows == 2)
            return ret;
        for(int i = 3; i <=numRows; ++i)
        {
            vector<int> new_level;
            new_level.insert(new_level.begin(), 1);
            vector<int> prev = ret.back();
            for(int i = 0; i < prev.size()-1; ++i)
            {
                int element = prev[i]+prev[i+1];
                new_level.push_back(element);
            }
            new_level.insert(new_level.end(), 1);
            ret.push_back(new_level);
        }
        return ret;
    }
};
