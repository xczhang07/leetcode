class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        if(n <= 0)
            return ret;
        string temp = "ZABCDEFGHIJKLMNOPQRSTUVWXY";
        while(n > 0)
        {
            int idx = n%26;
            ret = temp[idx] + ret;
            n = (n-1)/26;
        }
        return ret;
    }
};


Conclusion:
create a template to map the module value to the english charactors...
then we use the input number to mode 26, the module value as the index of the string to search the target charactor.
after each map, we divide it into 26 again.

Time Complexity is: O(logn)
Space Complexity is: O(1)
