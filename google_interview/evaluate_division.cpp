给一个输入文件：每行A, B, ratio。要求查询：A，B的ratio是多少。天真的我一看，诶！不就hashmap吗？
然而，写了一半，面试官才说，还得recursive地找，例如找A，C的ration要先找A，B，然后找B，C。
我郁闷了，最后没写完real code，就写了sudo code。

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) 
    {
        unordered_map<string, Node*> parent;
        vector<double> ret;
        
        for(int i = 0; i < equations.size(); ++i)
        {
            string eq1 = equations[i].first;
            string eq2 = equations[i].second;
            double val = values[i];
            if(!parent.count(eq1) && !parent.count(eq2))
            {
                parent[eq1] = new Node(val);
                parent[eq2] = new Node(1.0);
                parent[eq1]->parent = parent[eq2];
            }
            else if(!parent.count(eq1))
            {
                parent[eq1] = new Node();
                parent[eq1]->val = val*parent[eq2]->val;
                parent[eq1]->parent = parent[eq2];
            }
            else if(!parent.count(eq2))
            {
                parent[eq2] = new Node();
                parent[eq2]->val = parent[eq1]->val/val;
                parent[eq2]->parent = parent[eq1];
            }
            else
                unionNode(parent[eq1], parent[eq2], parent, val);
        }
        
        
        for(int i = 0; i < queries.size(); ++i)
        {
            string q1 = queries[i].first;
            string q2 = queries[i].second;
            if(parent.count(q1) == 0 || parent.count(q2) == 0 || find(parent, parent[q1]) != find(parent, parent[q2]))
                ret.push_back(-1);
            else
                ret.push_back(parent[q1]->val/parent[q2]->val);
        }
        return ret;
    }
    
private:
    struct Node
    {
        Node* parent;
        double val;
        
        Node(double val = 0.0)
        {
            this->val = val;
            this->parent = this;
        }
    };
    
    
    void unionNode(Node* node1, Node* node2, unordered_map<string, Node*>& parent, double val)
    {
        Node* p1 = find(parent, node1);
        Node* p2 = find(parent, node2);
        double ratio = node2->val * val / node1->val;
        for(auto iter = parent.begin(); iter != parent.end(); ++iter)
        {
            if(find(parent, iter->second) == p1)
                iter->second->val *= ratio;
        }
        p1->parent = p2;
        return;
    }
    
    Node* find(unordered_map<string, Node*>& parent, Node* node)
    {
        while(node != node->parent)
            node = node->parent;
        return node;
    }
    
};
