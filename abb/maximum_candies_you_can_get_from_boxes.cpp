// leetcode 1298
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> myBoxQ;
        unordered_set<int> boxSet(initialBoxes.begin(), initialBoxes.end());
        for(int box: initialBoxes) {
            if(status[box] == 1) {
                myBoxQ.push(box);
                boxSet.erase(box);
            }
        }
        int totalCandies = 0;
        unordered_set<int> keySet;
        while(!myBoxQ.empty()) {
            int box = myBoxQ.front();
            myBoxQ.pop();
            totalCandies += candies[box];
            for(int cBox: containedBoxes[box]) {
                if(status[cBox] == 1 or keySet.count(cBox)) {
                    myBoxQ.push(cBox);
                } else {
                    boxSet.insert(cBox);
                }
            }
            for(int boxKey: keys[box]) {
                if(boxSet.count(boxKey)) {
                    myBoxQ.push(boxKey);
                    boxSet.erase(boxKey);
                }
                keySet.insert(boxKey);
            }
        }
        return totalCandies;
    }
};
