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

    void inorder(TreeNode* root, vector<int>& in) {
        if(!root) {
            return;
        }
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    TreeNode* buildBalanceTree(int l, int r, vector<int>& inorder) {
        if(l > r) {
            return NULL;
        }
        int m = l + (r-l)/2;
        TreeNode* root = new TreeNode(inorder[m]);
        root->left = buildBalanceTree(l, m-1, inorder);
        root->right = buildBalanceTree(m+1, r, inorder);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        if(root == NULL) {
            return root;
        }
        vector<int> inorder_travel;
        inorder(root, inorder_travel);
        return buildBalanceTree(0, inorder_travel.size()-1, inorder_travel);
    }
};
