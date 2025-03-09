class Solution {
public:
    int binarySearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size()-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(arr[m] == target) {
                return m;
            } else if(arr[m] < target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return -1;
    }

    bool checkIfExist(vector<int>& arr) {
        if(arr.size() == 0 || arr.size() == 1) {
            return false;
        }     
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); ++i) {
            int idx = binarySearch(arr, arr[i]*2);
            if(idx != -1 && idx != i) {
                return true;
            }
        }
        return false;
    }
};

time complexity is: O(nlogn)
space complexity is: O(1)
