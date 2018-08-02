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
    /* dfs solution */
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        int max_depth = -1;
        int curr_depth = 0;
        if(root == NULL)
            return ret;
        dfs(ret, root, max_depth, curr_depth);
        return ret;
    }
    
    void dfs(vector<int>& ret, TreeNode* root, int& max_depth, int curr_depth)
    {
        /* 
         dfs to resolve this issue. 
         set two variables to record whether or not the right side node has been visited
         if curr_depth is greater than max_depth, we need to insert the node's value into
         result list, then update the max_depth value. if the curr_depth is less or equal to max_depth,
         which means this level has already been visited, no operation.
         */
        if(!root)
            return;
        if(curr_depth > max_depth){
            ret.push_back(root->val);
            max_depth = curr_depth;
        }
        dfs(ret, root->right, max_depth, curr_depth+1); // we guarrente that visit right-side first of all
        dfs(ret, root->left, max_depth, curr_depth+1);
        return;
    }
};

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
    vector<int> rightSideView(TreeNode* root) {
	/* bfs solution */
        vector<int> ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* prev;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            if(curr == NULL)
            {
                ret.push_back(prev->val);
                if(!q.empty())  q.push(NULL); //a tag before the most right view node.
            }
            else
            {
                prev = curr;
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ret;
    }
    
    
};

Conclusion:
a middle level leetcode issue, we can use both dfs and bfs to resolve this issue.
Time Complexity: O(n)
Space Complexity: O(n)


