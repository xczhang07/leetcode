class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1)
            return 0;
        vector<bool> primes(n,true);
        primes[0] = false;
        primes[1] = false;
        int count = 0;
        for(int i = 2; i < sqrt(n); ++i)
        {
            int j = i*i;
            while(j < n)
            {
                primes[j] = false;
                j += i;
            }
        }
        
        for(int i = 2; i < primes.size(); ++i)
        {
            if(primes[i])
                ++count;
        }
        return count;
    }
};


Conclusion: an easy algorithm issue, no any other comments.

Time Complexity: O(n)
Space Complexity: O(1)
