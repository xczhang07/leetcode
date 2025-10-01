bool compare(const vector<int>& e1, const vector<int>& e2) {
        return e1[2] < e2[2];
    }
// sample solution: https://leetcode.com/problems/minimize-maximum-component-cost/solutions/6951796/simple-union-find/?envType=company&envId=apple&favoriteSlug=apple-thirty-days
// Time Complexity: O(nlogn)
class Solution {
public:
    int find(int idx, vector<int>& parent) {
        if(parent[idx] == idx) {
            return idx;
        }
        return find(parent[idx], parent);
    }

    bool unite(int n1, int n2, vector<int>& parent) {
        n1 = find(n1, parent);
        n2 = find(n2, parent);
        if(n1 != n2) {
            parent[n1] = n2;
            return true; // union success
        }
        return false;
    }

    int minCost(int n, vector<vector<int>>& edges, int k) {
        vector<int> parent(n,0);
        sort(edges.begin(), edges.end(), compare);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        int cnt = n;
        for(vector<int>& edge: edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            int cost = edge[2];
            if(unite(n1, n2, parent)) {
                cnt -= 1;
            }
            if(cnt == k) {
                return cost;
            }
        }
        return 0;
    }
};
