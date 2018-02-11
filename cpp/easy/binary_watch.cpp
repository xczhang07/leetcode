class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> time_combination;
        for(int i = 0; i < 12; ++i)
        {
            for(int j = 0; j < 60; ++j)
            {
                if(bitset<10>( (i<<6) | j ).count() == num)
                {
                    time_combination.emplace_back(to_string(i) + (j >= 10 ? ":" : ":0") + to_string(j));
                }
            }
        }
        return time_combination;
    }
};


Conclusion: an easy algorithm issue, but it is style is very standard. We use bitset to solve this issue, which is very easy understandable
and efficient.
