Solution#1 DFS
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
        if(!node)
            return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        m[node] = newNode;
        dfs(node, m);
        return m[node];
    }
    
    void dfs(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& m)
    {
        if(node == NULL)
            return;
        for(int i = 0; i < node->neighbors.size(); ++i)
        {
            UndirectedGraphNode* n = node->neighbors[i];
            if(!m.count(n))
            {
                UndirectedGraphNode* t = new UndirectedGraphNode(n->label);
                m[n] = t;
                m[node]->neighbors.push_back(t);
                dfs(n, m);
            }
            else
               m[node]->neighbors.push_back(m[n]);
        }
        return;
    }
};

Time Complexity is: O(n)
Space Complexity is: O(n)


Solution#2 BFS solution

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
        if(!node)
            return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
        m[node] = newNode;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            for(int i = 0; i < top->neighbors.size(); ++i)
            {
                auto n = top->neighbors[i];
                if(!m.count(n))
                {
                    UndirectedGraphNode* t = new UndirectedGraphNode(n->label);
                    m[n] = t;
                    m[top]->neighbors.push_back(m[n]);
                    q.push(n);
                }
                else
                    m[top]->neighbors.push_back(m[n]);
            }
        }
        return m[node];
    }
    
    
};

Time Complexity is: O(n)
Space Complexity is: O(n)
