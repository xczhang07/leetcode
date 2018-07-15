class Solution {
public:
    string toLowerCase(string str) {
        for(int i = 0; i < str.size(); ++i)
            str[i] = tolower(str[i]);
        return str;
    }
};


Conclusion: an easy algorithm issue, using the builtin function can resolve this issue


Time Complexity: O(n)
Space Complexity: O(1)
