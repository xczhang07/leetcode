class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for(auto str : A)
        {
            string odd, even;
            for(int i = 0; i < str.size(); i+=2)
                even += str[i];
            for(int i = 1; i < str.size(); i+=2)
                odd += str[i];
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            s.insert(even + odd);
        }
        return s.size();
    }
};

/*
Time Complexity is: O(nklogk)
Space Complexity is: O(nk)
*/
