class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int len1 = A.size();
        int len2 = B.size();
        int times = 1;
        string temp = A;
        while(temp.size() < len2)
        {
            temp += A;
            times++;
        }
        if(temp.find(B) != -1)
            return times;
        temp += A;
        if(temp.find(B) != -1)
            return times+1;
        return -1;
    }
};


Conclusion: an easy algorithm on leetcode. 
1. first, we need to add A until A.size() >= B.size().
2. second, if A.find(B) == -1, we should add one more time A; then if A.find(B) != -1, return times+1.


Time Complexity: O(n)
Space Complexity: O(1)
