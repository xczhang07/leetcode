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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right)
    {
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL || right == NULL)
            return false;
        else if(left->val == right->val)
            return isMirror(left->right, right->left) && isMirror(left->left, right->right);
        return false;
    }
};


Conclusion:
An easy algorithm issue on leetcode, check a tree whether or not is a symmetric tree.
we can use recursive to travel the entire tree, then we can get the result.

Time Complexity: according to travel the entire tree, the time complexity is: O(n)
Space Complexity: according to the recursive call, the worst case is the call stack is: O(n)

    
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<string> level;
            for(int i = 0; i < n; ++i)
            {
                TreeNode* top = q.front();
                q.pop();
                if(top == NULL)
                {
                    level.push_back("#");
                    continue;
                }
                else
                    level.push_back(to_string(top->val));
                if(top->left)
                    q.push(top->left);
                else
                    q.push(NULL);
                if(top->right)
                    q.push(top->right);
                else
                    q.push(NULL);
            }
            int i = 0;
            int j = level.size()-1;
            while(i < j)
            {
                if(level[i] != level[j])
                    return false;
                ++i;
                --j;
            }
        }
        return true;
    }
    
   
};
