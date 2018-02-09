class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int less_dist = INT_MAX;
        int large_dist = INT_MAX;
        char ret1 = 0;
        char ret2 = 0;
        bool all_small = true;
        for(char& c: letters)
        {
            int tmp_dist = c - target;
            if(tmp_dist > 0)
            {
                all_small = false;
                if(tmp_dist < large_dist)
                {
                    large_dist = tmp_dist;
                    ret1 = c;
                }
            }
            else
            {
                if(tmp_dist < less_dist)
                {
                    less_dist = tmp_dist;
                    ret2 = c;
                }
            }
        }
        if(all_small)
            return ret2;
        else
            return ret1;
    }
};

Conclusion:
an easy algorithm question, but we need to consider the letters wrap around case (this case only happen all the input element in letters 
is smaller than the target value, in this case, we need to use the element minus target charactor, thus we get the negative value, eg: -1, -2...
if one element is close to the target element in this case, the negative value should also smaller). Another case is a little bit easy, we can get the
result once one element is larger than the input target value. According to the above two cases, we need to define two result variables, one is for case1,
another is for case2.

Time Complexity: O(n)
Space Complexity: O(1)

/* upper_bound solution */
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<char>::iterator upper = upper_bound(letters.begin(), letters.end(), target);
        if(upper != letters.end())
            return *upper;
        else
            return letters[0]; //because the input array has been sorted.
    }
};


