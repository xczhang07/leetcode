class Solution {
public:
    vector<int> origin;
    vector<int> back;     //back to original
    Solution(vector<int> nums) {
        
        back=nums;
        origin=nums;
      
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return back;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        next_permutation(origin.begin(),origin.end());
        return origin;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
 
 /*
 Conclusion:
 an ood design algorithm issue, middle level on leetcode, we can directly use c++ "next_permutation" function to resolve it.
 */


class Solution {
public:
    vector<int> origin;
    vector<int> back;     //back to original
    Solution(vector<int> nums) {
        origin=nums;
      
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return origin;
        
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret = origin;
        for(int i = 0; i < ret.size(); ++i)
        {
            int t = i + rand()%(ret.size()-i);
            swap(ret[i], ret[t]);
        }
        return ret;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
