class TrieNode
{
    public:
        TrieNode* child[26];
        bool isWord;
        TrieNode():isWord(false)
        {
            for(TrieNode*& ch : child)
                ch = NULL;
        }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* t = root;
        for(auto w : word)
        {
            int idx = w - 'a';
            if(!t->child[idx])
                t->child[idx] = new TrieNode();
            t = t->child[idx];
        }
        t->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* t = root;
        for(auto w : word)
        {
            int idx = w - 'a';
            if(!t->child[idx])
                return false;
            else
                t = t->child[idx];
        }
        return t->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* t = root;
        for(auto w : prefix)
        {
            int idx = w - 'a';
            if(!t->child[idx])
                return false;
            t = t->child[idx];
        }
        return true;
    }
    
    private:
        TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
