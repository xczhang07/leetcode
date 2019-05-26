
In a string composed of 'L', 'R', and 'X' characters, like "RXXLRXRXL", 
a move consists of either replacing one occurrence of "XL" with "LX", or replacing one occurrence of "RX" with "XR".
Given the starting string start and the ending string end, 
return True if and only if there exists a sequence of moves to transform one string to the other.

Example:

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: True
Explanation:
We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX


Time Complexity is: O(n)
Space Complexity is: O(n)

class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size() != end.size())
            return false;
        string s1, s2;
        int n = start.size();
        for(int i = 0; i < n; ++i)
        {
            if(start[i] != 'X')
                s1 += start[i];
            if(end[i] != 'X')
                s2 += end[i];
        }
        if(s1 != s2)
            return false;
        
        int i = 0, j = 0;
        while(i < n && j < n)
        {
            if(start[i] == 'X')
                ++i;
            else if(end[j] == 'X')
                ++j;
            else
            {
                if((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                    return false;
                ++i;
                ++j;
            }
        }
        return true;
    }
};
