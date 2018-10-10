bool comparePair(pair<int,int> p1, pair<int,int> p2)
{
    return (p1.first + p1.second < p2.first + p2.second); 
}

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        /*
        a priority queue issue, we need to learn how to customize priority queue.
        time complexity: O(n^2)
        space complexity: O(k)
        
        */
        vector<pair<int, int>> ret;
        int size1 = nums1.size();
        int size2 = nums2.size();
        int l1 = min(size1, k);
        int l2 = min(size2, k);
        priority_queue<pair<int,int>, vector<pair<int,int>>, function<bool(pair<int,int>, pair<int, int>)>> pq(comparePair);
        for(int i = 0; i < l1; ++i)
        {
            for(int j = 0; j < l2; ++j)
            {
                if(pq.size() < k)
                    pq.push(make_pair(nums1[i], nums2[j]));
                else
                {
                    int sum = nums1[i] + nums2[j];
                    int top = pq.top().first + pq.top().second;
                    if(sum < top)
                    {
                        pq.pop();
                        pq.push(make_pair(nums1[i],nums2[j]));
                    }
                }
            }
        }
        while(!pq.empty())
        {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};
