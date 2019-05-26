看起来不是很senior的中国小哥，lz一开始去错building了所以到了面试的会议室就没有寒暄直接开始。 找到tree 里面一个node的K th ancestor。 
记得是蠡口原题但是不记得题号了。限制用O(K) space. Backtraking。

TreeNode* findKthAncestor(TreeNode* root, TreeNode* node, TreeNode*& parent, int& k)
{
    if(!root)
        return NULL;
    TreeNode* l = findKthAncestor(root->left, node, parent, k);
    TreeNode* r = findKthAncestor(root->right, node, parent, k);
    if(l || r || root == node)
    {
        if(k > 0)
            --k;
        else if(k == 0)
        {
            parent = root;
            return NULL;
        }
        return root;
    }
    return NULL;
}
