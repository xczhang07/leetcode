class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k < 0)
            return 0;
        unordered_map<int, int> mymap;
        int ret = 0;
        for(int num:nums)
            mymap[num]++;
        for(auto it:mymap)
        {
            if(mymap.count(it.first+k))
            {
                if(k == 0)
                {
                    if(it.second > 1)
                    {
                        if(it.second != -1)
                        {
                            ret++;
                            it.second = -1;
                        }
                    }
                }
                else
                    ret++;
            }
        }
        return ret;
    }
};


Conclusion:
an easy algorithm issue, at the beginning I am goint to use set, then I find out it is very hard to avoid the k==0 case! then I use map instead
of set in this case. Insert each element of the input array into map, and then use the count function to search whether or not the element+k is
in the map.

The reason to use map:
 1. reduce the repeat number in the input array. key maps the number value, value maps the occurance of the value in the input array. eg:
    if the input array is: [1,1,2,3], k is 1
    we expect the result should be: [1,2], [2,3] return 2, in this case, map helps to avoid the repeat number in the input array
 2. we need to take care one of the specific case, which is the k == 0:
    if k == 0, the occurance number help us to find the unique pair, eg:
    input is: [1,1,1,2,3], k is 0:
    the map should be as following:
    {1:3, 2:1, 3:1}
    the expectation result is: [1,1], return 1; thus, if k is 0, and the value of the key is larger than 1, the ret plus one and we set 
    the value to -1(in order to avoid the duplicate result).
 
 Time Complexity is: O(n)
 Space Complexity is: O(n)
