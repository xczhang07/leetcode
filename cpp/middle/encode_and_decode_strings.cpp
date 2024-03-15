class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encode;
        for(string& s: strs) {
            encode += to_string(s.size()) + "." + s;
        }
        return encode;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> original;
        int i = 0;
        while(i < s.size()) {
            int len = 0;
            while(isdigit(s[i])) {
                len = len*10 + (s[i]-'0');
                ++i;
            }
            ++i; // skip '.'.
            string str = s.substr(i, len);
            i += len;
            original.push_back(str);
        }
        return original;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
