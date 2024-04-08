Reference link: https://www.cnblogs.com/grandyang/p/14401556.html

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int totalCost = 0;
        int n = costs.size()/2;
        vector<int> refund;
        for(auto& cost: costs) {
            totalCost += cost[0];
            refund.push_back(cost[1]-cost[0]);
        }
        sort(refund.begin(), refund.end());
        for(int i = 0; i < n; ++i) {
            totalCost += refund[i];
        }
        return totalCost;
    }
};
