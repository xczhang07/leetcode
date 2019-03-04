给一个2叉树root，里面可能有环。把多余的edge打断，然后返回root

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int value)
    {
        this->left = NULL;
        this->right = NULL;
        this->val = value;
    }
};

void removeHelper(TreeNode*& root, unordered_set<TreeNode*>& s)
{
    if(!root)
        return;
    s.insert(root);
    if(root->left)
    {
        if(s.count(root->left))
            root->left = NULL;
        else
            removeHelper(root->left, s);
    }
    if(root->right)
    {
        if(s.count(root->right))
            root->right = NULL;
        else
            removeHelper(root->right, s);
    }
    return;
}


TreeNode* removeEdges(TreeNode* root)
{
    if(!root)
        return NULL;
    unordered_set<TreeNode*> s;
    removeHelper(root, s);
    return root;
}

void printTree(TreeNode* root)
{
    if(!root)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0; i < n; ++i)
        {
            auto t = q.front();
            q.pop();
            cout<<t->val<<" ";
            if(t->left)
                q.push(t->left);
            if(t->right)
                q.push(t->right);
        }
        cout<<endl;
    }
    return;
}

int main()
{
  TreeNode* root = new TreeNode(0);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node5->right = root;
    node5->left = node2;
    
    root = removeEdges(root);
    
    printTree(root);
    
    
    return 0;
}
