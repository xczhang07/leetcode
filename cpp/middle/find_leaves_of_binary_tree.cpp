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
