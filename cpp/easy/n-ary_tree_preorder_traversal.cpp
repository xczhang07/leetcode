/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> preorder;
        if(!root)
            return preorder;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* parent = st.top();
            st.pop();
            preorder.push_back(parent->val);
            for(int i = parent->children.size()-1; i >= 0; --i)
                st.push(parent->children[i]);
        }
        return preorder;
    }
};


Conclusion:
an easy level question on leetcode. preorder travel the n-ary tree.
create a stack, from right to left to push the child's node into stack.
every time pop out the top from stack, keep the value, then its order is preorder travsersal

Time Complexity: O(n)
Space Complexity: O(n)
