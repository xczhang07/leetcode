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
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        long long hash_val1 = 0;
        long long hash_val2 = 0;
        dfs(root1, hash_val1);
        dfs(root2, hash_val2);
        return hash_val1 == hash_val2;
    }
    
    void dfs(TreeNode* root, long long& hash_val)
    {
        if(!root)
            return;
        if(root->left == NULL && root->right == NULL)
        {
            hash_val = hash_val * 31 + root->val;
            return;
        }
        dfs(root->left, hash_val);
        dfs(root->right, hash_val);
        return;
    }
};

/*
Conclusion:
an easy level algorithm issue on leetcode, the easiest way is to travel the tree with dfs and get the leaf node list,
then compare the two lists. In this case, the space complexity of this issue is not O(1)
we can use hash integer solution to hash the root sum value, and then compare.
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
