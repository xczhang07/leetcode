class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int end = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ')
            {
                end = i-1;
                reverseString(start, end, s);
                start = i+1;
            }
        }
        reverseString(start, s.size()-1, s); //do not forget the last word in the input string
        return s;
    }
    
    void reverseString(int start, int end, string& s)
    {
        while(start < end)
        {
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            ++start;
            --end;
        }
    }
};

Conclusion:
reverse each word in the sentence is OK, implement a helper function to reverse each word with start index and
end index, the whitespace is used to distinguish each word.
Keypoint:
1. there is only one whitespace between each two adjacent words.
2. do not forget to reverse the last word in the given sentence.

Time Complexity: O(n^2)
Space Complexity: O(1)
