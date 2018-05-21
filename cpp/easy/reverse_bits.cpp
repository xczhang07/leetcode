class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; n>0; i++, n=n>>1)    
            if(n&1!=0)  
                ans |= 1<<(31-i);  
        return ans;
    }
};


Conclusion: an easy level question on leetcode. 

Time Complexity: O(n)
Space Complexity: O(1)
