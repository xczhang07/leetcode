class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ret;
        if(left > right)
            return ret;
        int travel = left;
        bool self_dividing = true;
        while(travel <= right)
        {
            int tmp = travel;
            self_dividing = true;
            while(tmp != 0)
            {
                int digit = tmp%10;
                if(digit == 0 || (travel%digit != 0))
                {
                    self_dividing = false;
                    break;
                }
                tmp /= 10;
            }
            if(self_dividing)
                ret.push_back(travel);
            travel++;
        }
        return ret;
    }
};


Conclusion:
an easy level algorithm issue, mathmatic problem.



