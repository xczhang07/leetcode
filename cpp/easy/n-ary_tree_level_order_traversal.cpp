/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> level_order;
        if(!root)
            return level_order;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;
            for(int i = 0; i < size; ++i)
            {
                Node* top = q.front();
                q.pop();
                for(auto child: top->children)
                    q.push(child);
                level.push_back(top->val);
            }
            level_order.push_back(level);
        }
        return level_order;
    }
};


Conclusion: an easy level issue of leetcode, traverse n-ary tree with bfs:
1. create a queue.
2. push the root into the queue.
3. while loop to iterate the queue unless the queue is empty.
4. caculate the size of the queue at the beginning of while loop, this size is each level size.
5. create an empty vector
6. iterate the size (which caculate in step 4) on queue, pop out node, then push all the childs of the node(just popup)into queue.
7. push the temp level into level_order two dimision array.

Time Complexity: O(n)
Space Complexity: O(n)
 
