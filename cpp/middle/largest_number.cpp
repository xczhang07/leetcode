class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return "";
        else if(nums.size() == 1)
            return to_string(nums[0]);
        sort(nums.begin(), nums.end(), 
                [](int a, int b)
                {
                    return to_string(a)+to_string(b) > to_string(b)+to_string(a);
                }
            );
        string ret;
        for(int i = 0; i < nums.size(); ++i)
            ret += to_string(nums[i]);
        if(ret[0] == '0')
            return "0";
        else
            return ret;
        
    }
};

/*
a middle level algorithm issue, in this case, we cannot use the standard sort, we have to customize our own sort method.
for example, given two integer a and b, we need to compare: "ab" > "ba" ?
after the comparsion, we just concatonate the nums' element to result, then we got the answer.
*/
