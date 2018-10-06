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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        /*
        using priority queue + dfs travel to resolve this issue.
        note: the default priority queue is max priority queue, which means the top element of 
        the priority queue is the max value. if the max priority queue store the pair element, 
        the priority queue sorted according to the first element of the pair.
        */
        priority_queue<pair<double,int>> q;
        vector<int> ret;
        dfs(root, target, k, q);
        while(!q.empty())
        {
            ret.push_back(q.top().second);
            q.pop();
        }
        return ret;
    }
    
    void dfs(TreeNode* root, double& target, int& k, priority_queue<pair<double, int>>& q)
    {
        if(!root)
            return;
        double diff = abs(target-root->val);
        if(q.size() < k)
            q.push(make_pair(diff, root->val));
        else
        {
            if(diff < q.top().first)
            {
                q.pop();
                q.push(make_pair(diff, root->val));
            }
        }
        dfs(root->left, target, k, q);
        dfs(root->right, target, k, q);
        return;
    }
};

/*
Conclusion:
Time Complexity: O(n)
Space Complexity: O(k+n)
*/
