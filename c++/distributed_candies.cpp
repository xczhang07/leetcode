class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        if(candies.size() % 2 != 0)
            return -1;
        unordered_set<int> kinds;
        for(int i = 0; i < candies.size(); ++i)
            kinds.insert(candies[i]);
        return min(kinds.size(), candies.size()/2);
    }
};


thinking: even if all the candies are unique eg: [1,2,3,4,5,6,7,8,9,10], the sister can't get more than half kind of the total number.
In this case, we can use set to get the total number of candies' kind, then we can use maths method min(kinds.size(), candies.size()/2) to
caculate the sister's max kind candies number to get.
