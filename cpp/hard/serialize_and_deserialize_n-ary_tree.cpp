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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string data;
        serializeHelper(root, data);
        return data;
    }
    
    void serializeHelper(Node* root, string& data)
    {
        if(!root)
            data += "*";
        else
        {
            data += to_string(root->val) + " " + to_string(root->children.size()) + " ";
            for(int i = 0; i < root->children.size(); ++i)
                serializeHelper(root->children[i], data);
        }
        return;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
    
    Node* deserializeHelper(istringstream& in)
    {
        string val;
        in >> val;
        if(val == "*") return NULL;
        string size;
        in >> size;
        Node* root = new Node(stoi(val), {});
        for(int i = 0; i < stoi(size); ++i)
        {
            root->children.push_back(deserializeHelper(in));
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
