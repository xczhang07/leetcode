232. Tiny Url
Given a long url, make it shorter. To make it simpler, let's ignore the domain name.

You should implement two methods:

longToShort(url). Convert a long url to a short url.
shortToLong(url). Convert a short url to a long url starts with http://tiny.url/.
You can design any shorten algorithm, the judge only cares about two things:

The short key's length should equal to 6 (without domain and slash). And the acceptable characters are [a-zA-Z0-9]. For example: abcD9E
No two long urls mapping to the same short url and no two short urls mapping to the same long url.
Example
Given url = http://www.lintcode.com/faq/?id=10, run the following code (or something similar):

short_url = longToShort(url) // may return http://tiny.url/abcD9E
long_url = shortToLong(short_url) // return http://www.lintcode.com/faq/?id=10
The short_url you return should be unique short url and start with http://tiny.url/ and 6 acceptable characters. For example "http://tiny.url/abcD9E" or something else.

The long_url should be http://www.lintcode.com/faq/?id=10 in this case.

class TinyUrl {
public:
    /*
     * @param url: a long url
     * @return: a short url starts with http://tiny.url/
     */
    TinyUrl()
    {
        short2long.clear();
        long2short.clear();
        this->baseNum = 62;
        this->base62 = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    
    string longToShort(string &url) {
        // write your code here
        if(url.size() == 0)
            return NULL;
        if(long2short.find(url) != long2short.end())
            return "http://tiny.url/"+long2short[url];
        
        /* Generate short random key with base62 encoding algorithm */ 
        string short_key;
        int idx = 0;
        for(int i = 0; i < 6; ++i)
            short_key += this->base62[rand()%baseNum];
        
        while(short2long.find(short_key) != short2long.end())
        {
            short_key[idx] = this->base62[rand()%baseNum];
            idx = (idx+5)%6;
        }
        
        long2short[url] = short_key;
        short2long[short_key] = url;
        return "http://tiny.url/"+short_key;
    }

    /*
     * @param url: a short url starts with http://tiny.url/
     * @return: a long url
     */
    string shortToLong(string &url) {
        // write your code here
        int pos = url.find_last_of("/");
        string short_key = url.substr(pos+1);
        if(short2long.find(short_key) != short2long.end())
            return short2long[short_key];
        else
            return short_key;
    }

private:
    unordered_map<string, string> short2long;
    unordered_map<string, string> long2short;
    int baseNum;
    string base62;
};


