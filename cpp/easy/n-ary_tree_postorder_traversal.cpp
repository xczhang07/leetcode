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
    vector<int> postorder(Node* root) {
        vector<int> postorder;
        if(!root)
            return postorder;
        stack<Node*> st;
        st.push(root);
        while(!st.empty())
        {
            Node* parent = st.top();
            st.pop();
            for(auto child: parent->children)
                st.push(child);
            postorder.push_back(parent->val);
        }
        reverse(postorder.begin(), postorder.end());
        return postorder;
    }
};


Conclusion: an easy level question on leetcode, very same with the issue n-ary tree preorder traversal.
Create a stack and reverse the final result

Time Complexity: O(n)
Space Complexity: O(n)
