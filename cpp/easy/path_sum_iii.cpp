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
    
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        int ret = 0;
        dfs(root, ret, sum);
        return ret+pathSum(root->left, sum)+pathSum(root->right, sum);
    }
    
    void dfs(TreeNode* root, int& ret, int& sum)
    {
        if(!root)
            return;
        sum = sum - root->val;
        if(sum == 0)
            ++ret;
        dfs(root->left, ret, sum);
        dfs(root->right, ret, sum);
        sum += root->val;
    }
};


Conclusion: an easy algorithm issue of leetcode, path sum, dfs tree traverse. very standard typical issue.

    
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
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        unordered_map<int,int> m;
        m[0] = 1;
        int tmp = 0;
        int ret = 0;
        dfs(root, tmp, m, sum, ret);
        return ret;
    }
    
    void dfs(TreeNode* root, int tmp, unordered_map<int, int>& m, int& sum, int& ret)
    {
        if(!root)
            return;
        tmp += root->val;
        if(m.count(tmp-sum))
            ret += m[tmp-sum];
        m[tmp]++;
        dfs(root->left, tmp, m, sum, ret);
        dfs(root->right, tmp ,m, sum, ret);
        m[tmp]--;
    }
};
