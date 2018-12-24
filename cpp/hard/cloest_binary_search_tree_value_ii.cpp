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
        vector<int> ret;
        if(!root)
            return ret;
        dfs_inorder(root, ret, target, k);
        return ret;
    }
    
    void dfs_inorder(TreeNode* root, vector<int>& ret, double& target, int& k)
    {
        if(!root)
            return;
        dfs_inorder(root->left, ret, target, k);
        if(ret.size() < k)
            ret.push_back(root->val);
        else if(abs(root->val-target) < abs(ret[0]-target))
        {
            ret.erase(ret.begin());
            ret.push_back(root->val);
        }
        else
            return;
        dfs_inorder(root->right, ret, target, k);
        return;
    }
};


Solution2: time complexity is less than O(n)

Time Complexity is: O(k)
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
        /* worst case, time complexity is O(n) */
        vector<int> ret;
        if(!root) return ret;
        stack<TreeNode*> pre, suc; /* pre stores the tree node's value which is less than target
                                      suc stores the tree node's value which is larger than target
                                   */
        while(root)
        {
            if(root->val <= target)
            {
                pre.push(root);
                cout<<root->val<<endl;
                root = root->right;
            }
            else
            {
                suc.push(root);
                cout<<root->val<<endl;
                root = root->left;
            }
        }
        
        while(k > 0)
        {
            if(pre.empty() && suc.empty())
                break;
            else if(suc.empty())
            {
                ret.push_back(pre.top()->val);
                getPre(pre);
            }
            else if(pre.empty())
            {
                ret.push_back(suc.top()->val);
                getSuc(suc);
            }
            else if(target-pre.top()->val <= suc.top()->val-target)
            {
                ret.push_back(pre.top()->val);
                getPre(pre);
            }
            else if(target-pre.top()->val > suc.top()->val-target)
            {
                ret.push_back(suc.top()->val);
                getSuc(suc);
            }
            --k;
        }
        return ret;
        
    }
    
    /* update the pre stack which is used to get the cloest root value to the target
    which is smaller than the target
    */
    void getPre(stack<TreeNode*>& pre)
    {
        if(pre.empty())
            return;
        TreeNode* top = pre.top();
        pre.pop();
        if(top->left)
        {
            pre.push(top->left);
            top = pre.top();
            while(top->right)
            {
                pre.push(top->right);
                top = top->right;
            }
        }
    }
    
    void getSuc(stack<TreeNode*>& suc)
    {
        if(suc.empty())
            return;
        TreeNode* top = suc.top();
        suc.pop();
        if(top->right)
        {
            suc.push(top->right);
            top = suc.top();
            while(top->left)
            {
                suc.push(top->left);
                top = top->left;
            }
        }
    }
    
   
};
