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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(!root)
            return ret;
        string path = to_string(root->val);
        getPath(ret, path, root);
        return ret;
    }
    
    void getPath(vector<string>& ret, string path, TreeNode* root)
    {
        if(!root)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            ret.push_back(path);
            return;
        }
        else
        {
            if(root->left)
                getPath(ret, path + "->" + to_string(root->left->val), root->left);
            
            if(root->right)
                getPath(ret, path + "->" + to_string(root->right->val), root->right);
            
            return;
        }
    }
};

Conclusion:
an easy level algorithm issue, using dfs can resolve the issue.

Time Complexity: O(n)
Space Complexity: O(1)
