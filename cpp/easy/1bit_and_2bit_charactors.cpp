class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool ret = true;
        for(int i = 0; i < bits.size();)
        {
            if(bits[i])
            {
                ret = false;
                i += 2;
            }
            else
            {
                ret = true;
                i += 1;
            }
        }
        return ret;
    }
};

分析:
因为2 charactors 有两种 11 和 10， 1 charactor 只有一种，就是0. 
我们便利整个bits 数组， 如果遇到1这个字节，肯定要往后推两位，所以i+=2, 并且设置返回值是false
如果遇到是0这个字节，推1位，i += 1， 符合题意，返回值是 true.

时间复杂度: O(n)
空间复杂度: O(1)
