class Solution {
public:
    Solution(vector<int> w) {
        sum = w;
        for(int i = 1; i < sum.size(); ++i)
            sum[i] += sum[i-1];
    }
    
    int pickIndex() {
        int rand_num = rand()%sum.back();
        int left = 0;
        int right = sum.size()-1;
        while(left < right)
        {
            int mid = left + (right-left)/2;
            if(sum[mid] <= rand_num)
                left = mid+1;
            else
                right = mid;
        }
        return right;
    }
    
private:
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 * great website is: http://www.cnblogs.com/grandyang/p/9784690.html
 */
 
 
