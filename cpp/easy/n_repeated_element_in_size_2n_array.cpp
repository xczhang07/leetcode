class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int,int> m;
        for(int num : A)
        {
            m[num]++;
            if(m[num] >= 2)
                return num;
        }
        return -1;
    }
};


/*
Time Complexity is: O(n)
space complexity is: O(n)
*/
