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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int h = 1;
        int idx = 1;
        vector<int> start;
        int ret = 0;
        dfs(root, start, h, idx, ret);
        return ret;
    }
    
    void dfs(TreeNode* root, vector<int>& start, int h, int idx, int& ret)
    {
        if(!root)
            return;
        if(h > start.size())
            start.push_back(idx);
        ret = max(ret, idx-start[h-1]+1);
        dfs(root->left, start, h+1, 2*idx, ret);
        dfs(root->right, start, h+1, 2*idx+1, ret);
        return;
    }
    
};


Solution 2: bfs

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 1));
        int ret = 1;
        while(!q.empty())
        {
            int n = q.size();
            int left = q.front().second;
            int right = left;
            for(int i = 0; i < n; ++i)
            {
                right = q.front().second;
                TreeNode* top = q.front().first;
                 
                q.pop();
                if(top->left)
                    q.push(make_pair(top->left, 2*right));
                if(top->right)
                    q.push(make_pair(top->right, 2*right+1));
            }
            ret = max(ret, right-left+1);
        }
        return ret;
    }
    
   
    
};
