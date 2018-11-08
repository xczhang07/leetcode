/* iteration travel binary tree in postorder */
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        stack<TreeNode*> output;
        vector<int> ret;
        if(!root)
            return ret;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* top = st.top();
            output.push(top);
            st.pop();
            if(top->left)
                st.push(top->left);
            if(top->right)
                st.push(top->right);
        }
        
        while(!output.empty())
        {
            ret.push_back(output.top()->val);
            output.pop();
        }
        return ret;
    }
};

/* recursive travel binary tree in postorder */

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
    vector<int> postorderTraversal(TreeNode* root) {
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
        dfs(root->right, ret);
        ret.push_back(root->val);
        return;
    }
};
