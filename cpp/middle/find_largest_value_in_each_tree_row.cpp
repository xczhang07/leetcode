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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) 
            return res;
        queue<TreeNode*> nodeQ;
        nodeQ.push(root);
        int max_val = INT_MIN;
        while(!nodeQ.empty())
        {
            max_val = INT_MIN;
            int n = nodeQ.size();
            for(int i = 0; i < n; ++i)
            {
                TreeNode* tmpNode = nodeQ.front();
                nodeQ.pop();
                max_val = max(max_val, tmpNode->val);
                if(tmpNode->left)
                    nodeQ.push(tmpNode->left);
                if(tmpNode->right)
                    nodeQ.push(tmpNode->right);
            }
            res.push_back(max_val);
        }
        return res;
    }
};


Conclustion:
a middle level algorithm issue, we use BFS to tackle this issue. We caculate the total number of nodes at each level, then travel all
of them to find out the largest one in every level, at the mean time we got the next level nodes.

Time Complexity:
O(n)
Space Complexity:
O(n)

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
    vector<int> largestValues(TreeNode* root) {
        int height = getHeight(root);
        vector<int> ret(height, INT_MIN);
        dfs(root, 0, ret);
        return ret;
    }
    
    void dfs(TreeNode* root, int level, vector<int>& ret)
    {
        if(!root)
            return;
        if(root->val > ret[level])
            ret[level] = root->val;
        dfs(root->left, level+1, ret);
        dfs(root->right, level+1, ret);
        return;
    }
    
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int height = (left > right?left:right)+1;
        return height;
    }
};

dfs solution
