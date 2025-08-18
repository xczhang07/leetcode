class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        if(prices.empty()) {
            return "";
        }
        int minSum = 0;
        int maxSum = 0;
        vector<double> diff;
        double ret = 0.0;
        for(string p: prices) {
            double realPrice = stod(p);
            int fVal = floor(realPrice);
            int cVal = ceil(realPrice);
            if(realPrice-fVal) {
                diff.push_back(realPrice-fVal);
            }
            minSum += fVal;
            maxSum += cVal;
        }
        if(target < minSum or target > maxSum) {
            return "-1";
        }
        sort(diff.begin(), diff.end());
        int floorNum = maxSum-target;
        for(double d: diff) {
            if(floorNum) {
                ret += d;
                floorNum -= 1;
            } else {
                ret += (1.0-d);
            }
        }
        string minError = to_string(ret);
        return minError.substr(0, minError.find_first_of('.')+4);
    }
};
