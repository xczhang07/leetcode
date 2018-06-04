class Solution {
public:

    Solution()
    {
        dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        short2long.clear();
        long2short.clear();
        srand(time(NULL));
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(long2short.find(longUrl) != long2short.end())
            return "http://tinyurl.com/" + long2short[longUrl];
        int idx = 0;
        string randStr;
        for(int i = 0; i < 6; ++i)
            randStr.push_back(dict[rand()%62]);
        while(short2long.find(randStr) != short2long.end())
        {
            randStr[idx] = dict[rand()%62];
            idx = (idx + 1) % 5;
        }
        long2short[longUrl] = randStr;
        short2long[randStr] = longUrl;
        return "http://tinyurl.com/" + randStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string randStr = shortUrl.substr(shortUrl.find_last_of("/") + 1);
        return short2long.count(randStr) ? short2long[randStr] : shortUrl;
    }
    
private:
    unordered_map<string, string> short2long;
    unordered_map<string, string> long2short;
    string dict;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


Conclusion:
1. using base 62 encode method, 26 alpha lower case + 26 alpha upper case + 10 digits = 62
2. we use random to caculate the number to digit
