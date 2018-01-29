class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ret = 0;
        unordered_map<char, int> map;
        for(char e: J)
            map[e]++;
        for(char e: S)
        {
            if(map.count(e) > 0)
                ++ret;
        }
        return ret;
    }
};


Conclusion:
easy algorithm question, using hash map can resolve this one.



