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
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int depth = 0;
        dfs(root, depth);
        
        return depth;
    }
    
    int dfs(Node* root, int& depth)
    {
        if(!root)
            return 0;
        int height = 0;
        int max_height = 0; // define an max_height variable to record each level max height
        for(int i = 0; i < root->children.size(); ++i)
        {
            height = dfs(root->children[i], depth);
            max_height = max(max_height, height); // record each level max height
        }
        depth = max(max_height+1, depth);
        return max_height+1;
    }
    
};

Conclusion: an easy level algorithm issue, no comments.

Time Complexity: O(n)
Space Complexity: O(n)
