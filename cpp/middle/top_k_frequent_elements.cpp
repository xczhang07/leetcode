class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        if(nums.size() == 0)
            return ret;
        unordered_map<int, int> freq;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < nums.size(); ++i)
            freq[nums[i]]+=1;
        unordered_map<int, int>::iterator iter1 = freq.begin();
        
        for(iter1; iter1!=freq.end(); ++iter1)
        {
           pq.push(make_pair(iter1->second, iter1->first));
        }
        while(k--)
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
};

/*
Conclusion:
an middle level algorithm issue, not diffcult, using priority queue + hash_map can resolve the issue.
Time Complexity: O(n)
*/
