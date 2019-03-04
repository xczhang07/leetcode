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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0)
            return {};
        if(N == 1)
            return {new TreeNode(0)};
        vector<TreeNode*> ret;
        for(int i = 1; i < N; ++i)
        {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(N-i-1);
            for(int j = 0; j < left.size(); ++j)
            {
                for(int k = 0; k < right.size(); ++k)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ret.push_back(root);
                }
            }
        }
        
        return ret;
    }
};
