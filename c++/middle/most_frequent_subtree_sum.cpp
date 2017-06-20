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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ret;
        if(root == NULL)
            return ret;
        unordered_map<int, int> map;
        int max_sum = INT_MIN;
        get_tree_sum(root, max_sum, map);
        for(auto ele : map)
        {
            if(ele.second == max_sum)
                ret.push_back(ele.first);
        }
        return ret;
    }
    
    int get_tree_sum(TreeNode* root, int& max_count, unordered_map<int, int>& map)
    {
        if(!root)
            return 0;
        int sum = root->val;
        sum += get_tree_sum(root->left, max_count, map);
        sum += get_tree_sum(root->right, max_count, map);
        map[sum]++;
        max_count = max(max_count, map[sum]);
        return sum;
    }
};

Conclusion:
easy algorithm question, dfs preorder to solve it. time complexity is: O(n), n is the number of nodes
