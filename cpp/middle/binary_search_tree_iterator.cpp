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
        idx = 0;
        size = arr.size();
    }
    
    void dfs(TreeNode* root)
    {
        if(!root)
            return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
        return;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return idx < size;
    }

    /** @return the next smallest number */
    int next() {
        return arr[idx++];
    }
private:
    vector<int> arr;
    int idx;
    int size;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


Solution2 using stack to resolve the issue
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
        TreeNode* node = st.top();
        st.pop();
        int ret = node->val;
        if(node->right)
        {
            node = node->right;
            while(node)
            {
                st.push(node);
                node = node->left;
            }
        }
        return ret;
    }
    
private:
    stack<TreeNode*> st;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
