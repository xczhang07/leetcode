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
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL)
            return false;
        unordered_set<int> my_set;
        return dfs(root, :
        k, my_set);
    }
    
    bool dfs(TreeNode* root, int& k, unordered_set<int>& my_set)
    {
        if(!root)
            return false;
        int val = root->val;
        if(my_set.find(k-val) != my_set.end())
            return true;
        my_set.insert(val);
        return dfs(root->left, k, my_set) || dfs(root->right, k, my_set);
    }
};


Conclusion:
an easy algorithm issue, use an unordered set can achieve the algorithm goal.
Time Complexity: O(n)
Space Complexity: O(n)
