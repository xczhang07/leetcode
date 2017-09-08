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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)
            return -1;
        if(root->left == NULL && root->right == NULL)
            return -1;
        int second_min_val = -1;
        int root_val = root->val;
        dfs(root, second_min_val, root_val);
        return second_min_val;
    }
    
    void dfs(TreeNode* node, int& second_min_val, int& root_val)
    {
        if(!node)
            return;
        if(node->val > root_val && second_min_val == -1)
            second_min_val = node->val;
        if(second_min_val != -1)
        {
            if(node->val > root_val && node->val < second_min_val)
                second_min_val = node->val;
        }
        dfs(node->left, second_min_val, root_val);
        dfs(node->right, second_min_val, root_val);
    }
    
    
};


Conclusion:
设定一个变量值，沿着树找到比根节点值大的最小值，就是第二大的值。

Time Complexity: O(n)
Space Complexity: O(1)
