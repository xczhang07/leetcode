Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last leve

Soluction 1 BFS: 
time complexity is: O(n)
space complexity is: O(n)
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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        bool left = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL)
                left = false;
            else
            {
                if(left == false)
                    return false;
                q.push(top->left);
                q.push(top->right);
            }
        }
        return true;
    }
};

Soluction2 : DFS
Time Complexity is: O(n)
Space Complexity is: O(n)
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
     int countNodes(TreeNode* root)
     {
         if(!root) return 0;
         return 1 + countNodes(root->left) + countNodes(root->right);
     }
    
     int countByLevel(TreeNode* root, int start)
     {
         if(!root)
             return 0;
         int left = countByLevel(root->left, start*2);
         int right = countByLevel(root->right, start*2+1);
         return max(left, max(right, start));
     }
    
    bool isCompleteTree(TreeNode* root) {
       if(!root)
           return true;
        int nodes = countNodes(root);
        int level = countByLevel(root, 1);
        return nodes == level;
    }
};
