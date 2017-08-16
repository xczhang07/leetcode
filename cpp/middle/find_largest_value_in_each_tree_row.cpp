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
