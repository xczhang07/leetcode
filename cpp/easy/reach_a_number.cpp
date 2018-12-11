class Solution {
public:
    int reachNumber(int target) {
        int t = target;
       if (t < 0) t = -t;
        int i = 2, s = 1;
        while (s < t || (s-t) % 2) s += i++;
        return i-1;
    }
};
