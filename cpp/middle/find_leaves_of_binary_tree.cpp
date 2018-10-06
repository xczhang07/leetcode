/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        vector<vector<int>> ret;
        vector<int> leaves;
        while(root)
        {
            leaves.clear();
            getAllLeaves(root, leaves);
            ret.push_back(leaves);
        }
        return ret;
    }
    
    void getAllLeaves(TreeNode*& root, vector<int>& leaves)
    {
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            leaves.push_back(root->val);
            root = NULL;
            return;
        }
        getAllLeaves(root->left, leaves);
        getAllLeaves(root->right, leaves);
        return;
    }
};

Conclusion: get leaves of the tree, then set the leave to NULL, then get the leaves again until the tree becomes to NULL
Time Complexity: O(n^2)
Space Complexity: O(n^2)
    
    
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> leaves;
        if(!root)   
            return leaves;
        dfs(root, leaves);
        return leaves;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>& leaves)
    {
        /*dfs caculate the height for each node from the bottom of the tree */
        if(!root)
            return -1;
        int left_h = dfs(root->left, leaves);
        int right_h = dfs(root->right, leaves);
        int depth = max(left_h, right_h) + 1;
        if(depth >= leaves.size())
            leaves.resize(depth+1);
        leaves[depth].push_back(root->val);
        return depth;
    }
};

/*
dfs version to resolve this issue.
Time Complexity is: O(n)
Space Complexity is: O(n) recursive call for stack
*/
