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
    int kthSmallest(TreeNode* root, int k) {
        int num = 0;
        int ret = 0;
        if(!root)
            return -1;
        dfs(root, k, ret, num);
        return ret;
    }
    
    void dfs(TreeNode* root, int& k, int& ret, int& num)
    {
        if(!root)
            return;
        dfs(root->left, k, ret, num);
        num += 1;
        if(num == k)
            ret = root->val;
        dfs(root->right, k, ret, num);
        return;
    }
};

/*
Conclusion:
an middle level algorithm issue on leetcode, we can use inorder dfs to travel this tree.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
