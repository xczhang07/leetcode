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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        TreeNode* tempRight = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* travel = root;
        while(travel->right != NULL)
            travel = travel->right;
        travel->right = tempRight;
        flatten(root->right);
    }
};


/*
Conclusion:
convert a binary tree to linked list.
Time Complexity: O(n)
Space Complexity: O(1)
*/


Solution#2 iteration version

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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> st;
        while(root)
        {
            if(root->right)
                st.push(root->right);
            if(root->left)
            {
                root->right = root->left;
                root->left = NULL;
            }
            else if(!st.empty())
            {
                root->right = st.top();
                st.pop();
            }
            root = root->right;
        }
        return;
    }
};

Time Complexity is: O(n)
Space Complexity is: O(n)
