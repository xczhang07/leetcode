class Solution {
public:
    static bool compare(pair<int,int>& p1, pair<int, int>& p2)
    {
        return (p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second));
    }
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), compare);
        vector<pair<int,int>> ret;
        for(auto p: people)
            ret.insert(ret.begin()+p.second, p);
        return ret;
    }
};

Conclusion:
a middle level algorithm issue on leetcode. First of all, we can sort the input array according to the following regulations:
1. if the first element of p1 is greater than the first element of p2, then put p1 before of p2; otherwise, put p2 before of p1.
2. if the first element of p1 is equal to the first element of p2, then compare the second element, if the second element of p1 is less than the second element of p2.
then put the p1 ahead of p2; otherwise put p2 before p1.
3. then iterate the sorted array, create a new array, insert the element according to the second element position.

Time Complexity: O(n)
Space Complexity: O(n)
