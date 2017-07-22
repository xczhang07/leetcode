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
    //  here, we use BFS at here to travel each level of the Tree,
    //  in order to get the node level by level, we use a temp Q to store each level
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        int count = 0;
        double sum = 0;
        if(root == NULL)
            return ret;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            queue<TreeNode*> tmpQ;
            count = 0;
            sum = 0;
            while(!Q.empty())
            {
                TreeNode* tmpNode = Q.front();
                sum += tmpNode->val;
                Q.pop();
                if(tmpNode->left)
                    tmpQ.push(tmpNode->left);
                if(tmpNode->right)
                    tmpQ.push(tmpNode->right);
                ++count;
            }
            Q = tmpQ;
            ret.push_back(sum*1.0/count);
        }
        return ret;
    }
};

Conclusion:
Easy algorithm issue, BFS can solve the issue.
Time Complexity: O(n)
Space Complexity: O(n)
