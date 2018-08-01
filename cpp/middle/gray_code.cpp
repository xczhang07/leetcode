class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        if(n == 0)
            return ret;
        for(int i = 0; i < n; ++i)
        {
            int s = ret.size();
            for(int j = s-1; j >=0; --j)
                ret.push_back(ret[j]|1<<i);
        }
        return ret;
    }
};


Conclusion:
a middle level algorithm issue about to construct gray code, if you understand how to construct gray code, it's easy.
gray code: https://en.wikipedia.org/wiki/Gray_code
for example the 2 bits gray code as following:

00
01
11
10

we use the 2 bit sets to construct 3 bit gray code as following steps:
1st step, reflected the 2 bits set gray code:
 00
 01
 11
 10
-----
 10
 11
 01
 00

2nd step, we insert 0 into the above section, and insert 1 into the below section as following:

 000
 001
 011
 010
-----
 110
 111
 101
 100

the above is the 3 bits set gray code.

Time Complexity: O(n^2)
Space Complexity: O(n)
