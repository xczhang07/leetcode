class Solution {
public:
    bool isPossible(vector<int>& weights, int& capacity, int& days) {
        int dayCnt = 1;
        int load = 0;
        for(int i = 0; i < weights.size(); ++i) {
            if(weights[i] > capacity) {
                return false;
            }
            if(load + weights[i] <= capacity) {
                load += weights[i];
            } else {
                dayCnt += 1;
                load = weights[i];
                if(dayCnt > days) {
                    return false;
                }
            }
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int minWeight = INT_MAX;
        for(int i = 0; i < weights.size(); ++i) {
            sum += weights[i];
            if(weights[i] < minWeight) {
                minWeight = weights[i];
            }
        }
        int l = minWeight, r = sum;
        int ret = INT_MAX;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(isPossible(weights, m, days)) {
                ret = min(ret, m);
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ret;
    }
};
