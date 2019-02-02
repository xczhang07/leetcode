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


/* stack solution */

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
        if(s.empty())
            return NULL;
        stack<TreeNode*> st;
        int num = 0;
        int sign = 1;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '-')
                sign = -1;
            else if(isdigit(s[i]))
            {
                num = 0;
                while(i < s.size() && isdigit(s[i]))
                {
                    num = num * 10 + (s[i]-'0');
                    ++i;
                }
                --i;
                TreeNode* node = new TreeNode(num*sign);
                sign = 1;
                if(!st.empty())
                {
                    if(st.top()->left == NULL)
                        st.top()->left = node;
                    else
                        st.top()->right = node;
                }
                st.push(node);
            }
            else if(s[i] == ')')
                st.pop();
        }
        return st.top();
    }
    
    
};
