/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        /* using bfs to resolve the issue */
        if(!node)
            return NULL;
        UndirectedGraphNode* copyNode = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> my_map;
        my_map[node] = copyNode;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty())
        {
            UndirectedGraphNode* top = q.front();
            q.pop();
            for(int i = 0; i < top->neighbors.size(); ++i)
            {
                UndirectedGraphNode* neighbor = top->neighbors[i];
                if(my_map.find(neighbor) == my_map.end())
                {
                    UndirectedGraphNode* newNode = new UndirectedGraphNode(neighbor->label);
                    my_map[neighbor] = newNode;
                    my_map[top]->neighbors.push_back(newNode);
                    q.push(neighbor);
                }
                else
                    my_map[top]->neighbors.push_back(my_map[neighbor]);
            }
        }
        return my_map[node];
    }
};

/*
bfs travel to create a graph, not diffcult, no comments.

Time Complexity: O(N)
Space Complexity: O(N)
*/
