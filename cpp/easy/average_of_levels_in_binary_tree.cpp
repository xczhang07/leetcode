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

DFS version:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(!root) {
            return ret;
        }
        vector<vector<int>> nodes;
        dfs(root, 1, nodes);
        for(int i = 0; i < nodes.size(); ++i) {
            double sum = 0;
            for(int j = 0; j < nodes[i].size(); ++j) {
                sum += nodes[i][j];
            }
            double avg = sum*1.0/nodes[i].size();
            ret.push_back(avg);
        }
        return ret;
    }

    void dfs(TreeNode* root, int level, vector<vector<int>>& nodes) {
        if(!root) {
            return;
        }
        if(nodes.size() < level) {
            vector<int> vec;
            vec.push_back(root->val);
            nodes.push_back(vec);
        } else {
            nodes[level-1].push_back(root->val);
        }
        dfs(root->left, level+1, nodes);
        dfs(root->right, level+1, nodes);
    }
};
