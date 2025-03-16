class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(nums.size() == 0) {
            return false;
        }
        set<int> s;
        for(int i = 0; i < nums.size(); ++i) {
            auto lb = s.lower_bound(nums[i]);
            if(lb != s.end()) {
                if(*lb <= nums[i]+valueDiff) {
                    return true;
                }
            }
            if(lb != s.begin()) {
                auto pre = prev(lb);
                if(nums[i] <= *pre + valueDiff) {
                    return true;
                }
            }
            s.insert(nums[i]);
            if(s.size() > indexDiff) {
                s.erase(nums[i-indexDiff]);
            }
        }
        return false;
    }
};
