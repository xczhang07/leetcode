class TrieNode {
    public:
        TrieNode() {
            for(int i = 0; i < 26; ++i) {
                this->children[i] = NULL;
            }
            this->isWord = false;
        }

        TrieNode* children[26];
        bool isWord;
};

class Trie {
    public:
        Trie() {
            this->root = new TrieNode();
        }

        void insert(string word) {
            TrieNode* travel = this->root;
            for(char w: word) {
                int idx = w-'a';
                if(travel->children[idx] == NULL) {
                    travel->children[idx] = new TrieNode();
                }
                travel = travel->children[idx];
            }
            travel->isWord = true;
        }

        bool search(string word) {
            if(word.size() == 0) {
                return false;
            }
            TrieNode* travel = this->root;
            for(char w: word) {
                int idx = w - 'a';
                if(travel->children[idx] == NULL) {
                    return false;
                }
                travel = travel->children[idx];
            }
            return travel->isWord;
        }

        void check(int startIdx, string& text, vector<vector<int>>& ret) {
            TrieNode* travel = this->root;
            for(int i = startIdx; i < text.size(); ++i) {
                int idx = text[i]-'a';
                if(travel->children[idx] == NULL) {
                    return;
                }
                travel = travel->children[idx];
                if(travel->isWord) {
                    ret.push_back({startIdx, i});
                }
            }
        }

    private:
        TrieNode* root;
};

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> ret;
        Trie trie;
        // insert all words into the trie, which is ready for search.
        for(auto word: words) {
            trie.insert(word);
        }
        for(int i = 0; i < text.size(); ++i) {
            trie.check(i, text, ret);
        }
        return ret;
    }
};
