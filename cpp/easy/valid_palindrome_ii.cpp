class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l <= r)
        {
            if(s[l] == s[r])
            {
                ++l;
                --r;
            }
            else{
            /* removing the left */
                int ll = l + 1;
                int lr = r;
                while(ll <= lr && s[ll] == s[lr])
                {
                    ++ll;
                    --lr;
                }
                if(ll > lr) return true;
                /* removing the right */
                int rl = l;
                int rr = r-1;
                while(rl <= rr && s[rl] == s[rr])
                {
                    ++rl;
                    --rr;
                }
                if(rl > rr) return true;
                return false;
            }
            
        }
        return true;
    }
};

Conclusion: an easy algorithm issue, two pointer.
1. first move left and right, check the skip the s[l] == s[r].
2. find the element until meets the first s[l] != s[r]
3. try to remove the left value.
4. try to remove the right value.

Time Complexity: O(n)
Space Complexity: O(1)
