class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ret;
        int i = A.size()-1;
        int carry = 0;
        while(i >= 0 || K != 0 || carry)
        {
            int num1 = (i >= 0) ? A[i--] : 0;
            int num2 = (K != 0) ? (K%10) : 0;
            if(K)
                K /= 10;
            int sum = num1 + num2 + carry;
            carry = sum/10;
            sum %= 10;
            ret.insert(ret.begin(), sum);
        }
        return ret;
    }
};


Time Complexity is: O(n)
Space Complexity is: O(1)
