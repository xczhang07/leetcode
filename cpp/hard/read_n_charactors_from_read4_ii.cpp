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
