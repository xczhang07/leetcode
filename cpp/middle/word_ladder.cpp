class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /* a bfs algorithm issue */
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int step = 0;
        while(!q.empty())
        {
            int s = q.size();
            for(int i = 0; i < s; ++i)
            {
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return step+1;
                for(int j = 0; j < word.size(); ++j)
                {
                    for(char ch='a'; ch<='z'; ++ch)
                    {
                        string tempWord = word;
                        tempWord[j] = ch;
                        if(wordSet.find(tempWord) != wordSet.end() && tempWord != word)
                        {
                            q.push(tempWord);
                            wordSet.erase(tempWord);
                        }
                    }
                }
            }
            ++step;
        }
        return 0;
    }
};

/*
Conclusion: a middle level algorithm issue on leetcode.
using BFS to resolve the issue.
Time Complexity is: O(m*n)
*/
