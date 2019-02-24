Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6

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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int cnt = 0, height = 0, level = 0;
        TreeNode* travel = root;
        while(travel)
        {
            travel = travel->left;
            ++height;
        }
        
        travel = root;
        level = height-2;
        while(level >= 0)
        {
            TreeNode* left = travel->left;
            for(int i = 0; i < level; ++i)
                left = left->right;
            if(left)
            {
                travel = travel->right;
                cnt += pow(2, level);
            }
            else
                travel = travel->left;
            --level;
        }
        if(travel)
            cnt++;
        return pow(2, height-1)-1+cnt;
    }
};

Time Complexity is: O(logN)
Space Complexity is: O(1)
