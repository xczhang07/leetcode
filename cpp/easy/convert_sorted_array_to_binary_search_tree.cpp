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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;
        else if(nums.size() == 1)
            return new TreeNode(nums[0]);
        TreeNode* root = dfsPreorder(nums, 0, nums.size()-1);
        return root;
    }
    
    TreeNode* dfsPreorder(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfsPreorder(nums, start, mid-1);
        root->right = dfsPreorder(nums, mid+1, end);
        return root;
    }
};


Conclusion:
DFS Preorder + Binary Search
Time complexity: O(n)
