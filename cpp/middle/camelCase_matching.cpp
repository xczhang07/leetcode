class TrieNode {
    public:
        TrieNode() {
            for(int i = 0; i < 58; ++i) {
                children[i] = NULL;
            }
            this->isWord = false;
        }
        TrieNode* children[58];
        bool isWord;
};

class Trie {
public:
    Trie() {
        this->root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* travel = this->root;
        for(char c: word) {
            int idx = c - 'A';
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
        TrieNode* travel = root;
        for(char c: word) {
            int idx = c-'A';
            if(travel->children[idx] == NULL) {
                return false;
            }
            travel = travel->children[idx];
        }
        return travel->isWord;
    }

    bool matchPattern(string word) {
        if(word.size() == 0) {
            return false;
        }
        TrieNode* travel = root;
        for(char c : word) {
            int idx = c - 'A';
            if(travel->children[idx] != NULL) {
                travel = travel->children[idx];
            } else if (islower(c)) {
                continue;
            } else {
                return false;
            }
        }
        return travel->isWord;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie* t = new Trie();
        t->insert(pattern);
        vector<bool> ret;
        for(string query: queries) {
            ret.push_back(t->matchPattern(query));
        }
        return ret;
    }
};
