struct TrieNode
{
    TrieNode()
    {
        this->isWord = false;
        children = vector<TrieNode*>(26, NULL);
    }
    bool isWord;
    vector<TrieNode*> children;
};


class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string word)
    {
        if(word.size() == 0)
            return;
        TrieNode* t = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(t->children[word[i]-'a'] == NULL)
                t->children[word[i]-'a'] = new TrieNode();
            t = t->children[word[i]-'a'];
        }
        t->isWord = true;
    }
    
    bool search(string word)
    {
        if(word.size() == 0)
            return true;
        TrieNode* t = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(t->children[word[i]-'a'])
                t = t->children[word[i]-'a'];
            else
                return false;
        }
        return t->isWord;
    }
private:
    TrieNode* root;
};

bool isCompound(string word, Trie t, string& original)
{
    if(word.size() == 0)
        return true;
    for(int i = 1; i <= word.size(); ++i)
    {
        string word1 = word.substr(0,i);
        if(t.search(word1))
        {
            if(word1 != original)
                return isCompound(word.substr(i), t, original);
            else
                return false;
        }
    }
    return false;
}

string longestCompondString(vector<string>& wordList)
{
    if(wordList.size() <= 1)
        return "";
    string longest_string;
    int max_len = 0;
    Trie t;
    /* insert all the words into trie, build our trie */
    for(string word: wordList)
        t.insert(word);
    for(string word : wordList)
    {
        if(isCompound(word, t, word))
        {
            if(word.length() > max_len)
            {
                max_len = word.length();
                longest_string = word;
            }
        }
    }
    return longest_string;
}
