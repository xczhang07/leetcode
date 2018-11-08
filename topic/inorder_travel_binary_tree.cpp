/* iterative travel binary tree in inorder */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> st;
        if(!root)
            return ret;
        TreeNode* curr = root;
        while(curr!=NULL || !st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ret.push_back(curr->val);
            curr = curr->right;
        }
        return ret;
    }
};

/* recursive travel binary tree in inorder */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        dfs(root, ret);
        return ret;
    }
    
    void dfs(TreeNode* root, vector<int>& ret)
    {
        if(!root)
            return;
        dfs(root->left, ret);
        ret.push_back(root->val);
        dfs(root->right, ret);
        return;
    }
};
