class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size()-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            int missing_num = arr[m]-(m+1);
            if(missing_num < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l+k;
    }
};
