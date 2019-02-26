/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    int match(string& str1, string& str2)
    {
        int cnt = 0;
        for(int i = 0; i < str1.size(); ++i)
        {
            if(str1[i] == str2[i])
                cnt++;
        }
        return cnt;
            
    }
    
    void shrinkWordList(string& guessed, vector<string>& wordlist, int& cnt)
    {
        vector<string> tmp;
        for(int i = 0; i < wordlist.size(); ++i)
        {
            if(wordlist[i] == guessed)
                continue;
            else
            {
                int c = match(guessed, wordlist[i]);
                if(c == cnt)
                    tmp.push_back(wordlist[i]);
            }
        }
        wordlist = tmp;
    }
    
    void findSecretWord(vector<string>& wordlist, Master& master) {
        if(wordlist.size() == 0)
            return;
        
        int times = 10;
        string start = wordlist[rand()%wordlist.size()];
        
        while(times > 0)
        {
            int cnt = master.guess(start);
            if(cnt == 6)
                return;
            shrinkWordList(start, wordlist, cnt);
            start = wordlist[rand()%wordlist.size()];
            --times;
        }
        return;
    }
    
};
