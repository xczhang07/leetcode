The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Example 1:

Input: buf = "abc", n = 4
Output: "abc"
Explanation: The actual number of characters read is 3, which is "abc".
Example 2:

Input: buf = "abcde", n = 5 
Output: "abcde"
Note:
The read function will only be called once for each test cas

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
        int cnt = 0, cnt4 = 0;
        while(cnt < n)
        {
            cnt4 = read4(buf+cnt);
            cnt += cnt4;
            if(cnt4 < 4)
                break;
        }
        
        return min(cnt, n);
    }
};

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        if(n == 0)
            return 0;
        char buff[4];
        int read_bytes = 0;
        int write_bytes = 0;
        for(int i = 0; i < n; ++i)
        {
            if(write_bytes == read_bytes)
            {
                read_bytes = read4(buff);
                write_bytes = 0;
                if(read_bytes == 0)
                    return i;
            }
            buf[i] = buff[write_bytes++];
        }
        return n;
    }
};
