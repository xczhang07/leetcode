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
        if(n == 0)
            return 0;
        int cnt = 0;
        while(cnt < n)
        {
            char* temp = new char[4];
            int t = read4(temp);
            for(int i = 0; i < t; ++i)
                buffer.push(temp[i]);
            cnt += t;
            if(t < 4)
                break;
        }
        
        int l = min((int)buffer.size(), n);
        for(int i = 0; i < l; ++i)
        {
            buf[i] = buffer.front();
            buffer.pop();
        }
        return l;
    }
    
private:
    queue<char> buffer;
};



Solution 2
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
       if(n == 0)
           return 0;
        for(int i = 0; i < n; ++i)
        {
            if(read_bytes == write_bytes)
            {
                write_bytes = read4(buff);
                read_bytes = 0;
                if(write_bytes == 0)
                    return i;
            }
            buf[i] = buff[read_bytes];
            read_bytes++;
        }
        return n;
    }
    
private:
    int read_bytes = 0;
    int write_bytes = 0;
    char buff[4];
    
};
