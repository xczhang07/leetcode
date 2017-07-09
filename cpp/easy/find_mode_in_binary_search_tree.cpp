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
