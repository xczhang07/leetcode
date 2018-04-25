class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morseCode[] = {".-","-...","-.-.","-..",".","..-.","--.", 
                            "....","..",".---","-.-",".-..","--","-.","---",
                            ".--.","--.-",".-.","...","-","..-","...-",".--",
                            "-..-","-.--","--.."};
        unordered_set<string> transformation;
        for(int i = 0; i < words.size(); ++i)
        {
            string morse_str;
            for(int j = 0; j < words[i].size(); ++j)
            {
                morse_str += morseCode[words[i][j]-'a'];
            }
            transformation.insert(morse_str);
        }
        return transformation.size();
    }
};


Conclusion:
an easy algorithm issue, testing the knowledge of hash table, using the hash set can resolve the issue.

Time Complexity: O(n)
Space Complexity: O(n)
