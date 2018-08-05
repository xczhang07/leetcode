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
     vector<vector<int>> verticalOrder(TreeNode* root) {
         vector<vector<int>> ret;
         if(!root)
             return ret;
         map<int,vector<int>> level_map;
         queue<pair<int, TreeNode*>> q;
         q.push({0,root}); //set the root index to 0.
         while(!q.empty())
         {
             auto node = q.front();
             q.pop();
             level_map[node.first].push_back(node.second->val);
             if(node.second->left)
                 q.push({node.first-1,node.second->left});
             if(node.second->right)
                 q.push({node.first+1, node.second->right});
         }
         for(auto m:level_map)
             ret.push_back(m.second);
         return ret;
     }
   
};


Conclusion:
an middle level algorithm issue of leetcode, we using a map to collects the nodes at different level.
using a queue with element {level, Treenode} for BFS traveling.

Time Complexity: O(n)
Space Complexity: O(n)
