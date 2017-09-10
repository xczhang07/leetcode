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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        string path_sum;
        int sum = 0;
        getSum(root, sum, path_sum);
        return sum;
    }
    
    void getSum(TreeNode* root, int& sum, string path)
    {
        if(!root)
            return;
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            sum += stoi(path);
            return;
        }
        getSum(root->left, sum, path);
        getSum(root->right, sum, path);
    }
};


Conclusion:
比较简单的一道题，dfs preorder就可以处理这个问题。

Time Complexity: O(n)
Space Complexity: O(1)
