class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size())
            return {{}};
        vector<vector<string>> ret;
        unordered_set<string> visit;
        queue<vector<string>> q;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        q.push({beginWord});
        bool find = false;
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; ++i)
            {
                vector<string> path = q.front();
                q.pop();
                vector<string> newWords = addWord(path.back(), wordSet);
                for(int j = 0; j < newWords.size(); ++j)
                {
                    vector<string> newLevel(path.begin(), path.end());
                    newLevel.push_back(newWords[j]);
                    if(newWords[j] == endWord)
                    {
                        find = true;
                        ret.push_back(newLevel);
                    }
                    visit.insert(newWords[j]);
                    q.push(newLevel);
                }
            }
            
            if(find)
                break;
            for(auto iter1 = visit.begin(); iter1 != visit.end(); ++iter1)
                wordSet.erase(*iter1);
            visit.clear();
        }
        return ret;
    }
    
    
private:
    vector<string> addWord(string word, unordered_set<string>& wordList)
    {
        vector<string> ret;
        for(int i = 0; i < word.size(); ++i)
        {
            string tmp = word;
            for(char e='a'; e <= 'z'; ++e)
            {
                if(tmp[i] == e)
                    continue;
                tmp[i] = e;
                if(wordList.find(tmp) != wordList.end())
                    ret.push_back(tmp);
            }
        }
        return ret;
    }
};
