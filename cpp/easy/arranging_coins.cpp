class Solution {
public:
    int arrangeCoins(int n) {
        /* an math issue */
        /* invalidation check */
        if(n < 1)
            return 0;
        if(n == 1) /* corner case check */
            return 1;
        int rows = 0;
        int elements = 1;
        while(n >= elements)
        {
            n -= elements;
            elements += 1;
            rows += 1;
        }
        return rows;
    }
};

Conclusion: very easy algorithm issue, no comments

