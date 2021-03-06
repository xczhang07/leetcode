class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for(int num : nums)
        {
            top3.insert(num);
            if(top3.size() > 3)
                top3.erase(top3.begin());
        }
        if(top3.size() == 3)
            return *top3.begin();
        else
            return *top3.rbegin();
    }
};


Conclusion: we use set to address this issue, be aware that set will order its element in c++, so the begin() always return the minimum element of the set.
eg, if we insert 1,2,3,4 into a set, the set.begin() is 1 etc...

Time Complexity: O(n)
Space Complexity: O(n)

Solution2:
time complexity is: O(n)
space complexity is: O(1)
    
    class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN;
        long second = LONG_MIN;
        long third = LONG_MIN;
        for(auto num : nums)
        {
            if(num > first)
            {
                third = second;
                second = first;
                first = num;
            }
            else if(num < first && num > second)
            {
                third = second;
                second = num;
            }
            else if(num < second && num > third)
                third = num;
        }
        if(third == LONG_MIN)
            return first;
        else
            return third;
    }
};
