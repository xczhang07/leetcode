class Solution {
public:
    Solution(vector<int> nums) {
        this->input = nums;
    }
    
    int pick(int target) {
        int ret = -1;
        int cnt = 0;
        for(int i = 0; i < input.size(); ++i)
        {
            if(input[i] != target)
                continue;
            else
            {
                cnt++;
                if(rand()%cnt == 0)
                    ret = i;
            }
        }
        return ret;
    }
    
private:
    vector<int> input;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 * reference link: http://www.cnblogs.com/grandyang/p/5875509.html
 */
