如何从一个steam里面发现给定str 的 match。 函数是每次读入一个字符，然后返回 真假， 看是不是发现了匹配。


struct TrieNode
{
    int count;
    string sentence;
    unordered_map<char, TrieNode*> children;
    
    TrieNode()
    {
        this->count = 0;
        this->sentence = "";
    }
};

bool compare(pair<string,int>& p1, pair<string,int>& p2)
{
    if(p1.second == p2.second)
        return p1.first > p2.first;
    else
        return p1.second < p2.second;
}


class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string> sentences, vector<int> times) {
        root = new TrieNode();
        for(int i = 0; i < sentences.size(); ++i)
            insert(sentences[i], times[i]);
        curr = root;
    }
    
    void insert(string s, int count)
    {
        TrieNode* t = root;
        for(int i = 0; i < s.size(); ++i)
        {
            if(!t->children.count(s[i]))
                t->children[s[i]] = new TrieNode();
            t = t->children[s[i]];
        }
        t->sentence = s;
        t->count += count;
        return;
    }
    
    void dfs(TrieNode* node, priority_queue<pair<string,int>, vector<pair<string,int>>, function<bool(pair<string,int>&, pair<string, int>&)>>& pq)
    {
        if(node->sentence.size()!=0)
            pq.push(make_pair(node->sentence, node->count));
        if(node->children.size() == 0)
            return;
        for(auto e : node->children)
            dfs(e.second, pq);
    }
    
    vector<string> input(char c) {
        priority_queue<pair<string,int>, vector<pair<string,int>>, function<bool(pair<string,int>&, pair<string, int>&)>> pq(compare);
        if(c == '#')
        {
            insert(s, 1);
            s = "";
            curr = root;
            return {};
        }
        
        s.push_back(c);
        if(curr && curr->children.count(c))
            curr = curr->children[c];
        else
        {
            curr = NULL;
            return {};
        }
        
        if(curr->sentence.size() != 0)
            pq.push(make_pair(curr->sentence, curr->count));
        
        for(auto e: curr->children)
            dfs(e.second, pq);
        
        vector<string> ret;
        while(!pq.empty() && ret.size() < 3)
        {
            ret.push_back(pq.top().first);
            pq.pop();
        }
        
        return ret;
    }

private:
    TrieNode* root;
    TrieNode* curr;
    string s;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj.input(c);
 */
