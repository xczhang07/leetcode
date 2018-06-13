class Solution {
public:
    string customSortString(string S, string T) {
        string ret;
        for(char e : S)
        {
            int idx = T.find(e);
            while(idx != string::npos)
            {
                ret += e;
                T.erase(idx, 1);
                idx = T.find(e);
            }
        }
        ret += T;
        return ret;
    }
};

Conclusion:
an middle level algorithm issue of leetcode, first of all, scan the whole string of S. if it can be found that element in T, we add it until remove all of that element in T.
then add the rest of the T (which does not apperance in S)

Time Complexity: O(n^2)
Space Complexcity: O(n)



