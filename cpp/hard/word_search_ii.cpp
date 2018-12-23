class TrieNode
{
    public:
        TrieNode()
        {
            this->word = "";
            children = vector<TrieNode*>(26, NULL);
        }
    
    vector<TrieNode*> children;
    string word;
};

class Trie
{
    public:
        Trie()
        {
            this->root = new TrieNode();
        }
    
        void insert(string word)
        {
            TrieNode* t = root;
            for(auto w : word)
            {
                if(!t->children[w-'a'])
                    t->children[w-'a'] = new TrieNode();
                t = t->children[w-'a'];
            }
            t->word = word;
            return;
        }
    
        TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ret;
        Trie* tree = new Trie();
        for(string word : words)
            tree->insert(word);
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[0].size(); ++j)
            {
                if(tree->root->children[board[i][j]-'a'])
                {
                    search(ret, board, tree->root->children[board[i][j]-'a'], i, j);
                }
            }
        }
        return ret;
    }
    
    void search(vector<string>& ret, vector<vector<char>>& board, TrieNode* t, int i, int j)
    {
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        int m = board.size();
        int n = board[0].size();
        if(board[i][j] == '#')
            return;
        if(t->word.size() != 0)
        {
            ret.push_back(t->word);
            t->word.clear();
        }
        
        char tmp = board[i][j];
        board[i][j] = '#';
        for(auto dir : dirs)
        {
            int nx = i + dir.first;
            int ny = j + dir.second;
            if(nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if(t->children[board[nx][ny]-'a'])
                    search(ret, board, t->children[board[nx][ny]-'a'], nx, ny);
            }
        }
        board[i][j] = tmp;
        
        return;
    }
};
