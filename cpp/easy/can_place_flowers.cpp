class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0)
            return true;
        int prev, post = 0;
        for(int i = 0; i < flowerbed.size(); ++i)
        {
            if(n == 0)
                return true;
            if(flowerbed[i] == 0)
            {
                if(i == flowerbed.size()-1)
                    post = 0;
                else
                    post = flowerbed[i+1];
                if(i == 0)
                    prev = 0;
                else
                    prev = flowerbed[i-1];
                if(prev + post == 0)
                {
                    flowerbed[i] = 1;
                    --n;
                }
            }
        }
        if(n <= 0)
            return true;
        else
            return false;
    }
};

Conclusion:
Easy algorithm problem, for this question, we can go through each three elements of the array from index 0 to the length. If all the three elements
value are 0, set the middle one to 1, then minus 1 from n, after iterate the whole array, check whether or not n is large than 0.
Time Complexity: O(n)
Space Complexity: O(1)
