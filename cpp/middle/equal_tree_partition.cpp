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
    bool checkEqualTree(TreeNode* root) {
        if(!root)
            return false;
        unordered_set<int> s;
        int left_sum = getSum(root->left, s);
        int right_sum = getSum(root->right, s);
        int total = root->val + left_sum + right_sum;
        if(total % 2 != 0) return false;
        if(s.count(total/2)) return true;
        return false;
    }
    
    int getSum(TreeNode* root,  unordered_set<int>& s)
    {
        if(!root)
            return 0;
        int sum = root->val + getSum(root->left, s) + getSum(root->right, s);
        s.insert(sum);
        return sum;
    }
};
