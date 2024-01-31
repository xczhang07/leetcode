Sol1: Record frequency with hash_map.
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        unordered_map<int, int> freq_m;
        for(auto& row: mat) {
            for(auto& num: row) {
                freq_m[num]++;
            }
        }
        int ret = INT_MAX;
        int n = mat.size();
        for(auto iter = freq_m.begin(); iter != freq_m.end(); ++iter) {
            if(iter->second == n) {
                ret = min(ret, iter->first);
            }
        }
        if(ret != INT_MAX)
            return ret;
        else
            return -1;
    }
};

Sol2: Binary Search

class Solution {
public:

    bool binarySearch(vector<int>& nums, int& target) {
        int l = 0, r = nums.size()-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(nums[m] == target) {
                return true;
            } else if (nums[m] > target) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return false;
    }

    int smallestCommonElement(vector<vector<int>>& mat) {
        int target = 0;
        bool is_common = false;
        for(int i = 0; i < mat[0].size(); ++i) {
            int target = mat[0][i];
            is_common = true;
            for(int j = 1; j < mat.size(); ++j) {
                if(!binarySearch(mat[j], target)) {
                    is_common = false;
                    break;
                }
            }
            if(is_common){
                return target;
            }
        }
        return -1;
    }
};
