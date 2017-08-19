Issue Description
https://leetcode.com/problems/print-binary-tree/description/

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
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        if(height == 0)
        {
            vector<vector<string>> ret;
            return ret;
        }
        int column = pow(2, height)-1; //caculate a complete binary tree's node number
        vector<vector<string>> ret(height, vector<string>(column, ""));
        int level = 0;
        int start = 0;
        int end = column-1;
        setMatrix(root, ret, level, start, end);
        return ret;
    }
    
    void setMatrix(TreeNode* root, vector<vector<string>>& ret, int level, int start, int end)
    {
        if(!root)
            return;
        int mid = start + (end-start)/2;
        ret[level][mid] = to_string(root->val);
        setMatrix(root->left, ret, level+1, start, mid-1);
        setMatrix(root->right, ret, level+1, mid+1, end);
        return;
    }
    
    int getHeight(TreeNode* root)
    {
        if(!root)
            return 0;
        int left_height = getHeight(root->left);
        int right_height = getHeight(root->right);
        return ((left_height > right_height) ? left_height:right_height) +1;
    }
};

After reading the algorithm issue, we need to solve the following issues:
1.  how to get the height of a tree.
2.  how large is the 2D array we need to create.
3.  after got the 2D array, how do we set the value into the 2D array.

Let us address those issue one by one.

1. we can use dfs to get the height of the input tree.
2. According to observe the description of this algorithm issue, we can find out that the row number of the 2D is the height of the input tree;
then the column number of the 2D is the total number of the complete binary tree, which is 2^h-1; thus, the 2D is like: [h][2^h-1].
3. After we know how large is the 2D array, the node val is at the middle of each layer of the array and subarray. For example, the first row,
we need to set the root value at the middle of the first row array; then, for the second layer, we need to divide the second row into 2 parts,
for the 3rd layer, we divide the row into 4 parts, all of the node in the middle of the subarray. (the concept is similar with binary search)

Time Complexity: O(n)
Space Complexity: O(h*(2^h-1)) ===> h is the height of the binary tree.
