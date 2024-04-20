// Sort nearly sorted array
// Source: https://www.geeksforgeeks.org/nearly-sorted-algorithm/
vector<int> sortKArrays(vector<int> nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ret;
    for(int i = 0; i <= k; ++i) {
        pq.push(nums[i]);
    }
    for(int i = k+1; i < nums.size(); ++i) {
        ret.push_back(pq.top());
        pq.pop();
        pq.push(nums[i]);
    }
    while(pq.size() > 0) {
        ret.push_back(pq.top());
        pq.pop();
    }
    cout<<endl;
    return ret;
}
