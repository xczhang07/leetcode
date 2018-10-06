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
    
    int closestValue(TreeNode* root, double target) {
        double ret = root->val;
        dfs(root, target, ret);
        return (int)ret;
    }
    
    void dfs(TreeNode* root, double& target, double& ret)
    {
        if(!root)
            return;
        if(abs(root->val-target) < abs(target-ret))
            ret = root->val;
        dfs(root->left, target, ret);
        dfs(root->right, target,ret);
        return;
    }
   
};


/*
Conclusion:
Time Complexity is: O(n)
Space Complexity is: O(1)
*/
