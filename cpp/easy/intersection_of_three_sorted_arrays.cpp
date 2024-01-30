Solution1: two pointers

Time Complexity: O(N)
Space Complexity: O(N)
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> its1;
        vector<int> its2;
        int idx1 = 0, idx2 = 0, idx3 = 0;
        while(idx1 < arr1.size() && idx2 < arr2.size()) {
            if(arr1[idx1] == arr2[idx2]) {
                its1.push_back(arr1[idx1]);
                ++idx1;
                ++idx2;
            } else if (arr1[idx1] < arr2[idx2]) {
                ++idx1;
            } else {
                ++idx2;
            }
        }
        int i = 0;
        while(i < its1.size() && idx3 < arr3.size()) {
            if(its1[i] == arr3[idx3]) {
                its2.push_back(its1[i]);
                ++i;
                ++idx3;
            } else if (its1[i] < arr3[idx3]) {
                ++i;
            } else {
                ++idx3;
            }
        }
        return its2;
    }
};

Solution2 : Hashmap to calculate the frequency
Time Complexity: O(N)
Space Complexity: O(N)

class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        map<int, int> freq_m;
        vector<int> ans;
        for(int& num: arr1) {
            freq_m[num]++;
        }
        for(int& num: arr2) {
            freq_m[num]++;
        }
        for(int& num: arr3) {
            freq_m[num]++;
        }
        for(auto iter = freq_m.begin(); iter != freq_m.end(); ++iter) {
            if(iter->second == 3) {
                ans.push_back(iter->first);
            }
        }
        return ans;
    }
};

