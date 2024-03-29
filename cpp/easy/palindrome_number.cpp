class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        long ret = 0;
        reverse_number(x, ret);
        return x == ret;
    }
    
    
    void reverse_number(int x, long& ret)
    {
        if(!x)
            return;
        int num = x % 10;
        ret = ret * 10 + num;
        reverse_number(x/10, ret);
    }
};


Conclusion: to check a number whether or not is a palindrome number, eg 121 is a palindrome number.

For this issue, we can use iteration and recursive to solve it.

I use recursive to solve it, iteration is pretty simple.

Time Complexity: O(n)

Space Complexity: O(n) call stack of recursive
