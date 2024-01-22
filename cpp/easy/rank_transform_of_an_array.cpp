class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size() == 0) {
            return arr;
        }
        vector<int> tmp = arr;
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> m;
        int rank = 1;
        for(int i = 0; i < tmp.size(); ++i) {
            if(m.find(tmp[i]) == m.end()) {
                m[tmp[i]] = rank;
                rank++;
            }
        }
        for(int i = 0; i < arr.size(); ++i) {
            arr[i] = m[arr[i]];
        }
        return arr;
    }
};
