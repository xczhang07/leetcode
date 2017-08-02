class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1)
            return 9;
        long upper_bound = pow(10,n)-1;
        long lower_bound = pow(10,n-1);
        for(int i = upper_bound; i >= lower_bound; --i)
        {
            long candidate = buildPalindrome(i);
            for(long j = upper_bound; j*j >= candidate; --j)
            {
                if(candidate % j == 0)
                    return candidate%1337;
            }
        }
    }
    
    long buildPalindrome(int n)
    {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n)+s);
    }
};


Conclusion:
The tag of this issue is an easy level algorithm issue; however, I think this one is a middle level algorithm.

First of all, we need to check the corner case of this algorithm issue: if the input n is 1, the output should be 9.
Then, if the input n is larger than 1, we can know that:
if the n is 2, the result should in range (10,99)
if the n is 3, the result should in range (100, 999)
if the n is 4, the result should in range (1000, 9999)
....
thus, the upper bound should be: 10^n-1; the lower bound should be: 10^(n-1).
the third key step is to build the palindrome, we need to write a helper function to implement achieve this functionality as following:
if the input number is: 998, then its largest palindrome number is: 998899

after this we need to use a for loop to look up the matched result candidate from largest to smaller...


Time Complexity: O(10^n)
Space Complexity: O(1)
