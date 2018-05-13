/* In this post, implement the algorithm to caculate the max and min depth of binary tree */

#include<iostream>
using namespace std;


struct TreeNode 
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};


int get_max_height(TreeNode* root)
{
	if(!root)
		return 0;
	int left_height = get_max_height(root->left);
	int right_height = get_max_height(root->right);
	return max(left_height, right_height)+1;
}


int get_min_height(TreeNode* root)
{
	if(!root)
		return 0;
	else if(root->left == NULL && root->right == NULL)
		return 1;
	else if(root->left == NULL)
		return get_min_height(root->right)+1;
	else if(root->right == NULL)
		return get_min_height(root->left)+1;
	else
		return min(get_min_height(root->left), get_min_height(root->right))+1;
}



int main()
{
	/* let's construct a binary tree */
	TreeNode* root = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);
	root->left = node1;
	root->right = node2;
	node2->left = node3;
	node2->right = node4;
	/* In this case, the max height of this tree is 3, and the min height of this tree is 2 */
	cout<<"max height of the tree is: "<<get_max_height(root)<<endl;
	cout<<"min height of the tree is: "<<get_min_height(root)<<endl;
	return 1;
}
