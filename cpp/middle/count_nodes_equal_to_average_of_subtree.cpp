/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int count = 0;

    void averageHelper(TreeNode* node, TreeNode*& root, int& sum, int& num, int& avg) {
        if(!node) {
            return;
        }
        sum += node->val;
        num += 1;
        averageHelper(node->left, root, sum, num, avg);
        averageHelper(node->right, root, sum, num, avg);
        if(node == root) {
            avg = sum/num;
            if(root->val == avg) {
                count += 1;
            }
        }
    }

    int averageOfSubtree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        TreeNode* r = root;
        int sum = 0;
        int num = 0;
        int avg = 0;
        averageHelper(root, r, sum, num, avg);
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return count;
    }
};

Optimized solution:
Bottom Up
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int count = 0;

    pair<int,int> averageHelper(TreeNode* node, int sum, int num) {
        if(node == NULL) {
            return {0,0};
        }
        auto left_subtree = averageHelper(node->left, sum, num);
        auto right_subtree = averageHelper(node->right, sum, num);
        
        sum = left_subtree.first + node->val + right_subtree.first;
        num = left_subtree.second + 1 + right_subtree.second;
        if(node->val == (sum/num)) {
            count += 1;
        }
        return {sum, num};
    }

    int averageOfSubtree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        averageHelper(root, 0, 0);
        return count;
    }
};
