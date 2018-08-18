// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        if(buf == NULL)
            return 0;
        int cnt = 0;
        int cnt4 = 0;
        while(cnt < n)
        {
            int cnt4 = read4(buf+cnt);
            cnt += cnt4;
            if(cnt4 < 4)
                break;
        }
        return min(cnt,n);
    }
};

Conclusion:
an easy algorithm issue. no comments

Time Complexity: O(n)
Space Complexity: O(1)
