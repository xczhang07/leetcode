class Node
{
    public:
        Node(int val, int smaller)
        {
            this->val = val;
            this->smaller = smaller;
            this->left = NULL;
            this->right = NULL;
        }
        int val;
        int smaller; /* the smaller number than current value */
        Node* left;
        Node* right;
};

class Solution {

public:
    void insert(Node*& root, int num, int& cnt)
    {
        if(!root)
        {
            root = new Node(num ,0);
            return;
        }
        if(num < root->val)
        {
            root->smaller++;
            return insert(root->left, num, cnt);
        }
        else
        {
            cnt += root->smaller;
            if(root->val < num) cnt += 1;
            insert(root->right, num, cnt);
            return;
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret;
        Node* node = NULL;
        for(int i = nums.size()-1; i >= 0; --i)
        {
            int cnt = 0;
            insert(node, nums[i] ,cnt);
            ret.insert(ret.begin(), cnt);
        }
        return ret;
    }
};
