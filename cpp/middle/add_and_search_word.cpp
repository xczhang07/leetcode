class TrieNode
{
    public:
        TrieNode()
        {
            this->children = vector<TrieNode*>(26, NULL);
            this->is_word = false;
        }
        vector<TrieNode*> children;
        bool is_word;
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
            TrieNode* t = root;
            for(auto w : word)
            {
                int idx = w-'a';
                if(!t->children[idx])
                {
                    t->children[idx] = new TrieNode();
                }
                 t = t->children[idx];
            }
            t->is_word = true;
        }
    
        bool search(string word)
        {
            return search_helper(word, 0, root);
        }
    
        bool search_helper(string word, int idx, TrieNode* node)
        {
            if(idx == word.size())
                return node->is_word;
            if(word[idx] == '.')
            {
                bool ret = false;
                for(int i = 0; i < node->children.size(); ++i)
                {
                    if(node->children[i])
                        ret = ret || search_helper(word, idx+1, node->children[i]);
                }
                return ret;
            }
            else
            {
                if(!node->children[word[idx]-'a'])
                    return false;
                else
                    return search_helper(word, idx+1, node->children[word[idx]-'a']);
            }
        }
    
    private:
        TrieNode* root;
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        dict = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        dict->insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return dict->search(word);
    }
    
private:
    Trie* dict;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */

Time Complexity is: O(26^l)
    
Space Complexity is: O(26^l)
