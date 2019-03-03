You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0] 
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Time Complexity is: O(nlogn)

Solution #1
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
