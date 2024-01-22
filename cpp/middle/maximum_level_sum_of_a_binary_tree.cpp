/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int max_level = 0;
        int max_sum = INT_MIN;
        int level = 0;
        int level_sum = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            level_sum = 0;
            queue<TreeNode*> tmp_q;
            while(!q.empty()) {
                TreeNode* node = q.front();
                q.pop();
                level_sum += node->val;
                if(node->left) {
                    tmp_q.push(node->left);
                }
                if(node->right) {
                    tmp_q.push(node->right);
                }
            }
            q = tmp_q;
            level++;
            if(level_sum > max_sum) {
                max_sum = level_sum;
                max_level = level;
            }
        }
        return max_level;
    }
};
