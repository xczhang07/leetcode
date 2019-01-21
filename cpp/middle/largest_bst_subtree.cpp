/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 Time Complexity is: O(n)
 Space Complexity is: O(n)
 
 
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int ret = 0;
        int min = 0;
        int max = 0;
        isBST(root, ret, min, max);
        return ret;
    }
    
    bool isBST(TreeNode* root, int& res, int& min_val, int& max_val)
    {
        if(!root)
            return true;
        
        int left_min = 0, left_max = 0, right_min = 0, right_max = 0;
        int left_size = 0, right_size = 0;
        bool left = isBST(root->left, left_size, left_min, left_max);
        bool right = isBST(root->right, right_size, right_min, right_max);
        if(left && right)
        {
            if((root->left == NULL || root->val > left_max) && (root->right == NULL || root->val < right_min))
            {
                res = 1 + left_size + right_size;
                min_val = root->left? left_min: root->val;
                max_val = root->right?right_max: root->val;
                return true;
            }
        }
        
        res = max(left_size, right_size);
        return false;
    }
    
};
