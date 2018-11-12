class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> ret(1,1);
        int i2 = 0, i3 = 0, i5 = 0;
        while(ret.size() < n)
        {
            int num2 = ret[i2]*2;
            int num3 = ret[i3]*3;
            int num5 = ret[i5]*5;
            int min_num = min(num2, min(num3, num5));
            if(min_num == num2)
                ++i2;
            if(min_num == num3)
                ++i3;
            if(min_num == num5)
                ++i5;
            ret.push_back(min_num);
        }
        return ret.back();
    }
};
