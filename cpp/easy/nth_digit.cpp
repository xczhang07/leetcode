class Solution {
public:
  int findNthDigit(int n) {
    --n;
    int64_t base = 1, cnt = 9, len = 1;
    while (true) {
        if (n < cnt * len) break;
        n -= cnt * len;
        base *= 10;
        cnt *= 10;
        ++len;
    }
    return to_string(base + n / len)[n % len] - '0';
}

};


Conclusion: an easy algorithm issue, mathmatic issue. 

Time Complexity: O(lgN)

Space Complexity: O(1)
