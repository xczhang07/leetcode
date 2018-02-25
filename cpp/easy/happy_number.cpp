class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> dict;
        dict.insert(n);
        while(n)
        {
            int num = n;
            int tmp = 0;
            while(num)
            {
                int rest = num % 10;
                tmp = tmp + rest * rest;
                num /= 10;
            }
            if(tmp == 1)
                return true;
            if(dict.count(tmp) > 0)
                return false;
            else
                dict.insert(tmp);
            n = tmp;
        }
        return false;
    }
};

Conclusion:
This is an easy level algorithm issue. No comments.



