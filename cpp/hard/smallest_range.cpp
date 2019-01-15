bool compare(pair<int,int> p1, pair<int,int> p2)
{
    return p1.first > p2.first;
}

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ret;
        if(nums.size() == 0 || nums[0].size() == 0)
            return ret;
        int n = nums.size();
        int currMax = INT_MIN;
        vector<int> idx(n, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>, pair<int,int>)>> pq(compare);
        for(int i = 0; i < nums.size(); ++i)
        {
            pq.push(make_pair(nums[i][0], i));
            idx[i] = 1;
            currMax = max(currMax, nums[i][0]);
        }
        ret = {pq.top().first, currMax};
        
        while(idx[pq.top().second] < nums[pq.top().second].size()) /* guarante each queue has at least one element in the pq */
        {
            auto p = pq.top();
            pq.pop();
            int smallest = p.first;
            int i = p.second;
            pq.push(make_pair(nums[i][idx[i]], i));
            currMax = max(currMax, nums[i][idx[i]]);
            idx[i]++; /* increase the index for each list for next use */
            if(ret[1]-ret[0] > currMax-pq.top().first)
                ret = {pq.top().first, currMax};
        }
        return ret;
    }
};


Time Complexity is: O(m*n*logn) m is the average length of the list, n is the total list number
Space Complexity is: O(n)
