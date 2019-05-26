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
        for(int i = 0; i < n; ++i)
        {
            if(read_bytes == write_bytes)
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
    
    char buff[4];
    int read_bytes = 0;
    int write_bytes = 0;
    
};
