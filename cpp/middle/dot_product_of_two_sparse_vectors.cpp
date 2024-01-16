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


Option #2

class SparseVector {
public:
    vector<pair<int, int>> sparse_vec;

    int binarySearch(int index, int left, int right) {
        while(left <= right) {
            int mid = left + (right-left)/2;
            if(sparse_vec[mid].first == index) {
                return sparse_vec[mid].second;
            } else if (sparse_vec[mid].first < index) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }

    SparseVector(vector<int> &nums) {
        // Convert nums to unordered map
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                sparse_vec.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        vector<pair<int,int>> guest = vec.sparse_vec;
        if(sparse_vec.size() > guest.size()) {
            for(int i = 0; i < guest.size(); ++i) {
                int key = guest[i].first;
                int val = guest[i].second;
                ans += val * binarySearch(key, 0, sparse_vec.size()-1);
            }
        } else {
            for(int i = 0; i < sparse_vec.size(); ++i) {
                int key = sparse_vec[i].first;
                int val = sparse_vec[i].second;
                ans += val * vec.binarySearch(key, 0, guest.size()-1);
            }
        }
        return ans;
    }
    
};

Time Complexity : O(MlogN)
Space Complexity : O(M+N)

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
