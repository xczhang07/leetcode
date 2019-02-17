Time Complexity is: O(n)
Space Complexity is: O(1)

class Solution {
public:
    long long pow(int x, int n)
    {
        if(n == 0)
            return 1;
        else if(n == 1)
            return x%1337;
        long long power = pow(x, n/2);
        if(n % 2 == 0)
            return power * power % 1337;
        else
            return power * power * x % 1337;
    }
    
     int superPow(int a, vector<int>& b) {
        if(b.size() == 0)
            return a;
         if(a == 0)
             return 0;
         if(a == 1)
             return 1;
         long long ret = 1;
         for(int i = 0; i < b.size(); ++i)
         {
             ret = pow(ret, 10)* pow(a, b[i])%1337;
         }
         return ret;
    }
    
   
};
