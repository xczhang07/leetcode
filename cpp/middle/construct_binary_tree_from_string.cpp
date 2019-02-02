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
TreeNode* builder(string s, int& idx)
{
    int num = 0;
    int sign = 1;
    TreeNode* root = new TreeNode(0);
    for(idx; idx < s.size(); ++idx)
    {
        if(s[idx] == '-')
            sign = -1;
        while(idx < s.size() && isdigit(s[idx]))
        {
            num = num * 10 + (s[idx]-'0');
            ++idx;
        }
        root->val = num * sign;
        if(s[idx] == '(')
        {
            TreeNode* child = builder(s, ++idx);
            if(root->left == NULL)
                root->left = child;
            else
                root->right = child;
        }
        else if(s[idx] == ')')
            return root;
    }
    return root;
}
    
    
TreeNode* str2tree(string s) {
    if (s.empty()) return NULL;
    int i = 0;
    return builder(s, i);
}

};
