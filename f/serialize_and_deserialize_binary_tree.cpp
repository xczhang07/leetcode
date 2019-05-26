Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 

You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"
Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Time Complexity is: O(n)
Space Complexity is: O(n)



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
    
    void serializeHelper(TreeNode* root, ostringstream& out)
    {
        if(!root)
        {
            out<<"# ";
            return;
        }
        out<<to_string(root->val) + " ";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
        return;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }
    
    TreeNode* deserializeHelper(istringstream& in)
    {
        string data;
        in >> data;
        if(data == "#")
            return NULL;
        TreeNode* root = new TreeNode(stoi(data));
        root->left = deserializeHelper(in);
        root->right = deserializeHelper(in);
        return root;
    }
    
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
            return NULL;
        istringstream in(data);
        return deserializeHelper(in);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
