class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(gas.size() != cost.size())
            return -1;
        int sum = 0;
        int total = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); ++i)
        {
            total += (gas[i]-cost[i]);
            sum += (gas[i]-cost[i]);
            if(sum < 0)
            {
                start = i+1;
                sum = 0;
            }
        }
        return total < 0? -1:start;
    }
};


/*
Conclusion:
a middle level algorithm issue, first of all, we need to make sure whether or not the total value is greater or equal to 0, then we caculate the sum value, if the sum value less than zero at a position, we can set the start to i+1
and sum to zero. if the total less than zero, return -1 else return start.
Time Complexity: O(n)
Space Complexity: O(1)
*/
