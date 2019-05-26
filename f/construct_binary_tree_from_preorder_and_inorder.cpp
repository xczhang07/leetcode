/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 Time Complexity is: O(n^2)
 Space Complexity is: O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(pre.size() == 0 || in.size() == 0)
            return NULL;
        if(pre.size() != in.size())
            return NULL;
        int rt = 0;
        return construct(pre, rt, in, 0, in.size()-1);
    }
    
    TreeNode* construct(vector<int>& pre, int& rt, vector<int>& in, int in_st, int in_end)
    {
        if(in_st > in_end)
            return NULL;
        TreeNode* root = new TreeNode(pre[rt]);
        int idx = getRoot(in, pre[rt]);
        rt++;
        root->left = construct(pre, rt, in, in_st, idx-1);
        root->right = construct(pre, rt, in, idx+1, in_end);
        return root;
    }
    
    int getRoot(vector<int>& in, int val)
    {
        for(int i = 0; i < in.size(); ++i)
        {
            if(in[i] == val)
                return i;
        }
        return -1;
    }
};
