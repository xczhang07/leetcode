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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ret;
        map<int, map<int, vector<int>>> node_map;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()) {
            int n = q.size();
            while(n > 0) {
                auto node = q.front();
                q.pop();
                pair<int,int> coordinate = node.second;
                int y = coordinate.first;
                int x = coordinate.second;
                node_map[y][x].push_back(node.first->val);
                if(node.first->left) {
                    q.push({node.first->left, {y-1, x+1}});
                }
                if(node.first->right) {
                    q.push({node.first->right, {y+1, x+1}});
                }
                --n;
            }
        }
        for(auto column_nodes: node_map) {
            vector<int> c;
            for(auto row_nodes: column_nodes.second) {
                vector<int> vec = row_nodes.second;
                sort(vec.begin(), vec.end());
                c.insert(c.end(), vec.begin(), vec.end());
            }
            ret.push_back(c);
        }
        return ret;
    }
};
