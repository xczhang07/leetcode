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
        for(int i = 0; i < n; ++i)
        {
            if(read_bytes == write_bytes)
            {
                write_bytes = read4(buff);
                read_bytes = 0;
                if(write_bytes == 0) /* handle file size smaller than n case */
                    return i;
            }
            buf[i] = buff[read_bytes++];
        }
        return n;
    }
    
    int write_bytes = 0;
    int read_bytes = 0;
    char buff[4];
};
