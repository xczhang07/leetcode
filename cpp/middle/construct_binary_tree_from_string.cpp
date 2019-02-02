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
    TreeNode* str2tree(string s) {
        if(s.size() == 0)
            return NULL;
        int idx = 0;
        return helper(s, idx);
    }
    
    
    TreeNode* helper(string s, int& idx)
    {
        if(idx >= s.size())
            return NULL;
        int start = idx;
        if(s[idx] == '-')
            ++idx;
        while(idx < s.size() && isdigit(s[idx]))
            ++idx;
        int num = stoi(s.substr(start, idx-start));
        TreeNode* root = new TreeNode(num);
        if(s[idx] == '(')
        {
            ++idx;
            root->left = helper(s, idx);
            ++idx;
        }
        if(s[idx] == '(')
        {
            ++idx;
            root->right = helper(s, idx);
            ++idx;
        }
        return root;
    }


};


/*
Time Complexity is: O(n)
Space Complexity is: O(n)
*/
