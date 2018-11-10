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
   
	TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		if(pre.size() != post.size())
            return NULL;
        else if(pre.size() == 0)
            return NULL;
        int n = pre.size()-1;
        unordered_map<int,int> m; 
        for(int i = 0; i < post.size(); ++i)
            m[post[i]] = i;
        return constructTree(pre, 0, n, post, 0, n, m);
	}
    
    TreeNode* constructTree(vector<int>& pre, int a, int b, vector<int>& post, int c, int d, unordered_map<int,int>& m)
    {
        if(a > b || c > d)
            return NULL;
        TreeNode* root = new TreeNode(pre[a]);
        if(a == b)
            return root;
        int t = pre[a+1];
        int idx = m[t];
        int len = idx -c+1;
        root->left = constructTree(pre, a+1, a+len, post, c, idx, m);
        root->right = constructTree(pre, a+len+1, b, post, idx+1, d-1, m);
        return root;
    }
};

/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
