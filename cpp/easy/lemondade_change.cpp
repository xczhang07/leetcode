class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> my_map;
        my_map[5] = 0;
        my_map[10] = 0;
        my_map[20] = 0;
        for(auto bill:bills)
        {
            int change = bill-5;
            my_map[bill] += 1;
            if(change == 0)
                continue;
            else if(change == 5)
            {
                if(my_map[5] == 0)
                    return false;
                else
                    my_map[change] -= 1;
            }
            else if(change == 15)
            {
                if(my_map[10] != 0)
                {
                    my_map[10] -= 1;
                    if(my_map[5] != 0)
                        my_map[5] -= 1;
                    else
                        return false;
                }
                else
                {
                    if(my_map[5] < 3)
                        return false;
                    else
                        my_map[5] -= 3;
                }
            }
        }
        return true;
    }
};


Conclusion: resolve lemonade change leetcode issue, an easy level question. time complexity is O(n). space complexity is O(n).
