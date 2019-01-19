
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        /*
        four regions:
        [0,i-1], [i+1, j-1], [j+1, k-1], [k+1, n-1]
        i start from 1; 
        j start from 3;
        k start from 5;
        /* time complexity is: O(n^2)
            space complexity is: O(n)
        */
        */
        if(nums.size() == 0)
            return true;
        int n = nums.size();
        vector<int> sums = nums;
        for(int i = 1; i < nums.size(); ++i)
            sums[i] = sums[i-1] + nums[i];
        for(int j = 3; j < n-3; ++j)
        {
            unordered_set<int> s;
            for(int i = 1; i < j-1; ++i)
            {
                if(sums[i-1] == sums[j-1]-sums[i])
                    s.insert(sums[i-1]);
            }
            for(int k = j+1; k < n-1; ++k)
            {
                int s3 = sums[k-1]-sums[j];
                int s4 = sums[n-1]-sums[k];
                if(s3 == s4 && s.count(s3))
                    return true;
            }
        }
        return false;
    }
};
