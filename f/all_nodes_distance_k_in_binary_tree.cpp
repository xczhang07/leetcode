We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
 

Note:

The given tree is non-empty.
Each node in the tree has unique values 0 <= node.val <= 500.
The target node is a node in the tree.
0 <= K <= 1000.

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
    
    vector<int> ret;
    unordered_map<TreeNode*, TreeNode*> parents; /* child => parent */
    unordered_set<TreeNode*> visit;
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(!root || !target)
            return ret;
        findParent(root);
        dfs(target, K);
        return ret;
    }
    
    void dfs(TreeNode* node, int k)
    {
        if(!node)
            return;
        if(visit.count(node))
            return;
        visit.insert(node);
        if(k == 0)
        {
            ret.push_back(node->val);
            return;
        }
        dfs(node->left, k-1);
        dfs(node->right, k-1);
        dfs(parents[node], k-1);
        return;
    }
    
    /* find parent function */
    void findParent(TreeNode* node)
    {
        if(!node)
            return;
        if(node->left)
            parents[node->left] = node;
        if(node->right)
            parents[node->right] = node;
        findParent(node->left);
        findParent(node->right);
        return;
    }
    
    
};
