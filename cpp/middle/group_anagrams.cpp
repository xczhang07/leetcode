class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.size() == 0)
            return ret;
        unordered_map<string, vector<string>> my_map;
        for(auto e : strs)
        {
            string tmp = e;
            sort(tmp.begin(), tmp.end());
                my_map[tmp].push_back(e);
        }
        unordered_map<string, vector<string>>::iterator iter1 = my_map.begin();
        for(iter1; iter1 != my_map.end(); ++iter1)
            ret.push_back(iter1->second);
        return ret;
    }
};


/*
Conclusion:
an middle level algorithm issue, not diffcult, it is OK. 
Time Complexity: O(n)
Space Complexity: O(n)

*/
