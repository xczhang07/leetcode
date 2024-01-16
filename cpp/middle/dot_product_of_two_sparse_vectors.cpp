class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        // Convert nums to unordered map
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                sparse_vec[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        unordered_map<int, int> guest = vec.sparse_vec;
        for(auto e : guest) {
            if(sparse_vec.find(e.first) != sparse_vec.end()) {
                ans += e.second * sparse_vec[e.first];
            }
        }
        return ans;
    }

    unordered_map<int, int> sparse_vec;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
