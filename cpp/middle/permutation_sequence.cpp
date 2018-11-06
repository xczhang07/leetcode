class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        string num = "123456789";
        vector<int> f(n, 1);
        /* caculate the (n-1)! result */
        for(int i = 1; i < n; ++i)
            f[i] = f[i-1]*i;
        k=k-1;
        for(int i = n; i >= 1; --i)
        {
            int idx = k/f[i-1]; /* caculate the current number idx */
            k = k % f[i-1];  /* caculate the next permutation idx */
            ret.push_back(num[idx]);
            num.erase(idx,1);
        }
        return ret;
    }
};


/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
