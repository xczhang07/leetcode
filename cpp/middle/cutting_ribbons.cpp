class Solution {
public:
    int upperBoundary(vector<int>& ribbons) {
        int upperBound = INT_MIN;
        for(int& r: ribbons) {
            if(r > upperBound) {
                upperBound = r;
            }
        }
        return upperBound;
    }

    bool isPossible(vector<int>& ribbons, int& k, int& len) {
        int count = 0;
        for(int r: ribbons) {
            if(r / len > 0) {
                count += r/len;
            }
            if(count >= k) {
                return true;
            }
        }
        return false;
    }


    int maxLength(vector<int>& ribbons, int k) {
        int l = 1;
        int r = upperBoundary(ribbons);
        int ret = 0;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(isPossible(ribbons, k, m)) {
                ret = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return ret;
    }
};
