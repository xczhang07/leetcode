Solution#1: 
using stack to manipulate the input tree.
Time Complexity is: 
hasNext() O(1)
next() worst case: O(n)

Space Complexity is: O(h), the stack will not store all the nodes.


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
       while(root)
       {
           st.push(root);
           root = root->left;
       }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        if(st.empty())
            return -1;
        TreeNode* top = st.top();
        st.pop();
        int val = top->val;
        if(top->right)
        {
            top = top->right;
            st.push(top);
            while(top->left)
            {
                top = top->left;
                st.push(top);
            }
        }
        return val;
    }
    
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
 Solution#2
 
 Time Complexity is:
 constructor :O(n)
 hasNext(): O(1)
 next(): O(1)
 
 Space Complexity is: O(n)
 
 /**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        dfs(root);
        size = nums.size();
        idx = 0;
    }
    
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
        return;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(idx == size)
            return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
       int val = nums[idx];
        idx++;
        return val;
    }
    
private:
    vector<int> nums;
    int size;
    int idx;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
