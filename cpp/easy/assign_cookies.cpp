class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ret = 0;
        if(g.size() == 0 || s.size() == 0)
            return ret;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = g.size()-1;
        int j = s.size()-1;
        while(i >= 0 && j >= 0)
        {
            if(s[j] >= g[i])
            {
                ret += 1;
                --j;
            }
            --i;
        }
        return ret;
    }
};

Conclusion:
Not hard algorithm issue, we just need to sort the two input arrays, then compare them from end to begin.
(we need to distributed the candy to children eventually; thus, we need to always minus 1 each loop of the children number, 
then, if one candy meets the requirement, we need to minus 1 of the candy number. )

Time complexity:

the sort should be O(nlogn), the while loop iteration is O(n).
