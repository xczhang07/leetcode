/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int camera = 0;
        int val = putCameras(root, camera);
        if(val == 0) /* this means the root node has not been monitored */
            ++camera;
        return camera;
    }
    
    int putCameras(TreeNode* root, int& camera)
    {
        if(!root)
            return 1; /* return 1 means we do not need to put the camera at this node */
        int l = putCameras(root->left, camera);
        int r = putCameras(root->right, camera);
        if(l == 0 || r == 0)
        {
            /* this means either the left side child or the right side child does not monitored 
            we need to put one camera at here */
            camera++;
            return 2; /* return 2 means there is a camera in the node */
        }
        else if(l == 2 || r == 2)
        {
            return 1; /* this means at least one of the left or child child has camera, we do
            not need to put camera at current node and this node still been covered */
        }
        else
            return 0; /* this means, both left and right child returns 1 and they are covered by camera, in this case
                        we do not need to put camera in the current node, we have to put camera to its parent */
    }
};

Time Complexity is: O(n)
Space Complexity is: O(h)
