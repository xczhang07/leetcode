String[][] words = {
        {"earth", "america"},
        {"america", "south america", "north america"},
        {"north america", "canada", "us"},
        {"canada", "ontario", "quebec", "calgary"},
        {"us", "california"}
};

每个array的第一个元素是parent，余下各元素都是这个parent的children。问题实现一个function，给两个单词，求出最近公共祖先。
这题不难，用HashMap和HashSet就好。注意一下corner case，比如word1是word2的祖先，和word2是word1的祖先。
以下是我准备的code（在实际面试过程中，面试官要求这个function就接受两个word作为input，build HashMap的过程另外实现，
于是我在constructor里build HashMap）：

string LCAOfWords(vector<vector<string>>& words, string word1, string word2)
{
    if(words.size() == 0)
        return NULL;
    if(word1.size() == 0 || word2.size() == 0)
        return NULL;
    unordered_map<string, string> parents;
    for(int i = 0; i < words.size(); ++i)
    {
        for(int j = 1; j < words[i].size(); ++j)
            parents[words[i][j]] = words[i][0];
    }
    
    unordered_set<string> ancestor;
    /*
     in case word2 is the ancestor of word1
     */
    ancestor.insert(word2);
    string tmp = word2;
    while(parents.count(tmp))
    {
        tmp = parents[tmp];
        if(word1 == tmp)
            return word1;
        ancestor.insert(tmp);
    }
    
    tmp = word1;
    while(parents.count(tmp))
    {
        tmp = parents[tmp];
        if(ancestor.count(tmp))
            return tmp;
        
    }
    return NULL;
}


class Node
{
public:
    Node(string s)
    {
        this->word = s;
    }
    string word;
    vector<Node*> _children;
};

Node* helper(unordered_map<string, vector<string>>& graph, string root)
{
    Node* newRoot = new Node(root);
    if(!graph.count(root))
        return newRoot;
    for(int i = 0; i < graph[root].size(); ++i)
        newRoot->_children.push_back(helper(graph, graph[root][i]));
    return newRoot;
}

Node* buildTree(vector<vector<string>>& words)
{
    if(words.size() == 0)
        return NULL;
    unordered_map<string, vector<string>> graph;
    for(int i = 0; i < words.size(); ++i)
    {
        for(int j = 1; j < words[i].size(); ++j)
            graph[words[i][0]].push_back(words[i][j]);
    }
    
    string root = words[0][0];
    Node* wordTree =  helper(graph, root);
    return wordTree;
}

void printWordTree(Node* root)
{
    if(!root)
        return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; ++i)
        {
            Node* t = q.front();
            q.pop();
            cout<<t->word<<" ";
            for(int j = 0; j < t->_children.size(); ++j)
            {
                if(t->_children[j] != NULL)
                    q.push(t->_children[j]);
            }
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
  vector<vector<string>> words = {
        {"earth", "america"},
        {"america", "south america", "north america"},
        {"north america", "canada", "us"},
        {"canada", "ontario", "quebec", "calgary"},
        {"us", "california"}
    };
    
    string word1 = "quebec";
    string word2 = "california";
    cout<<LCAOfWords(words, word1, word2)<<endl;
  return 0;
}
