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
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        unordered_map<int, int> counter;
        int max_value = INT_MIN;
        dfs(root, counter, max_value);
        for(auto it: counter)
        {
            if(it.second == max_value)
                ret.push_back(it.first);
        }
        return ret;
    }
    
    void dfs(TreeNode* root, unordered_map<int, int>& counter, int& max_value)
    {
        if(!root)
            return;
        counter[root->val]++;
        max_value = max(max_value, counter[root->val]);
        dfs(root->left, counter, max_value);
        dfs(root->right, counter, max_value);
    }
};


Conclusion:
Easy issue, Time complexity is: O(n), Space complexity is: O(n)

Solution II
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
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        int c = 1;
        int k = 1;
        TreeNode* prev = NULL;
        dfs(root, prev, ret, c, k);
        return ret;
    }
    
    void dfs(TreeNode* node, TreeNode*& prev, vector<int>& ret, int& c, int& k)
    {
        if(!node)
            return;
        dfs(node->left, prev, ret, c, k);
        if(prev)
        {
            if(prev->val == node->val)
                ++c;
            else
                c = 1;
        }
        if(c > k)
        {
            k = c;
            ret.clear();
            ret.push_back(node->val);
        }
        else if(c == k)
            ret.push_back(node->val);
        
        prev = node;
        dfs(node->right, prev, ret, c, k);
    }
    
};

Conclusion:
Easy issue, time complexity is: O(n), space complexity is: O(1)

find the most left node first, because bfs inorder sorting is an increase sorted array, so, reach the most left node and find it upper
level to upper level should be OK.
