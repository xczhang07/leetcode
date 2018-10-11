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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> tmp;
        if(!root)   return ret;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            tmp.clear();
            int size = q.size();
            while(size)
            {
                TreeNode* top = q.front();
                q.pop();
                --size;
                if(level % 2 == 0)
                    tmp.push_back(top->val);
                else
                    tmp.insert(tmp.begin(), top->val);
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
            }
            ret.push_back(tmp);
            level++;
        }
        return ret;
    }
};

/*
BFS can resolve this issue.
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
