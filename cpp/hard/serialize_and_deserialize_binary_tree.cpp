/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "x";
        string s = "(" + to_string(root->val) + ")";
        s = s + serialize(root->left) + serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return deserializeHelper(data, i);
    }
    
    TreeNode* deserializeHelper(string& data, int& i)
    {
        if(data[i++] == 'x')
        {
            cout<<i<<" "<<endl;
            return NULL;
        }
        int val = 0;
        string s = "";
        while(data[i++] != ')')
        {
            s += data[i-1];
        }
        val = stoi(s);
        TreeNode* root = new TreeNode(val);
        root->left = deserializeHelper(data, i);
        root->right = deserializeHelper(data, i);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

/*
Conclusion:
diffcult algorithm issue, when we do the conversion, the node which has the value needs to be converted as (1), the node which
is NULL, needs to be converted as 'x"
Time Complexity is: O(n)
Space Complexity is: O(n)
*/


Solution2 c++ stringstream 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }
    
private:
    TreeNode* deserializeHelper(istringstream& in)
    {
        string val;
        in>>val;
        if(val == "#")
            return NULL;
        else
        {
            TreeNode* root = new TreeNode(stoi(val));
            root->left = deserializeHelper(in);
            root->right = deserializeHelper(in);
            return root;
        }
    }
    
    void serializeHelper(TreeNode* root, ostringstream& out)
    {
        if(!root)
            out<<"# ";
        else
        {
            out<<root->val<<" ";
            serializeHelper(root->left, out);
            serializeHelper(root->right, out);
        }
         return;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
