class Solution {
public:
    int numWays(int n, int k) {
        /* if the post number is 0. */
        if(n == 0)
            return 0; 
        /*if the post number is n. */
        if(n == 1)
            return k;
        /*if the post number is 2*/
        int same = k; 
        int diff = k*(k-1);
        for(int i = 3; i <= n; ++i)
        {
            int pre_diff = diff;
            diff = (same + diff)*(k-1);
            same = pre_diff;
        }
        return (same + diff);
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(1)
a good tutorial as following:
https://www.youtube.com/watch?v=deh7UpSRaEY&t=7s
*/
