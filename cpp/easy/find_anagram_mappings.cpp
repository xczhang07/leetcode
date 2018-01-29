class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> ret;
        if(A.size() != B.size())
            return ret;
        unordered_map<int, int> my_map;
        for(int i = 0; i < B.size(); ++i)
            my_map[B[i]] = i;
        for(int i = 0; i < A.size(); ++i)
            ret.push_back(my_map[A[i]]);
        return ret;
    }
};

Conclusion:
an easy level algorithm, using hash_map can solve this issue.

Time Complexity: O(m+n)
Space Complexity: O(n)

m is A.size(), n is B.size()
