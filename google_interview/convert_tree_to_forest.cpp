struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int v)
	{
		this->left = NULL;
		this->right = NULL;
		this->val = v;
	}
};

void helper(TreeNode*& root, vector<TreeNode*>& list, unordered_set<TreeNode*>& s, TreeNode* parent, bool removeParent)
{
	if (root == NULL)
		return;
	if (s.count(root))
	{
		if (parent)
		{
			if (parent->left == root)
				parent->left = NULL;
			else
				parent->right = NULL;
		}
		TreeNode* left_t = root->left;
		TreeNode* right_t = root->right;
		root = NULL;
		helper(left_t, list, s, NULL, true);
		helper(right_t, list, s, NULL, true);
	}
	else
	{
		if (removeParent == true)
			list.push_back(root);
		helper(root->left, list, s, root, false);
		helper(root->right, list, s, root, false);
	}
}

vector<TreeNode*> tree2forest(TreeNode* root, vector<TreeNode*> removelist)
{
	vector<TreeNode*> ret;
	if (!root)
		return ret;
	bool removeParent = true;
	TreeNode* parent = NULL;
	unordered_set<TreeNode*> s(removelist.begin(), removelist.end());
	helper(root, ret, s, parent, removeParent);
	return ret;
}

int main()
{
  TreeNode* root = new TreeNode(0);
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node10 = new TreeNode(10);
	root->left = node1;
	root->right = node2;
	node1->left = node3;
	node1->right = node4;
	node2->left = node5;
	node2->right = node6;
	node3->left = node7;
	node3->right = node8;
	node4->left = node9;
	node4->right = node10;
  vector<TreeNode*> removelist = {root};

	vector<TreeNode*> forest = tree2forest(root, removelist);

	for (int i = 0; i < forest.size(); ++i)
	{
		cout << "tree " << i + 1 << " is: " << endl;
		printTree(forest[i]);
		cout << endl;
	}
  
  cout<<endl;
  
  return 0;

}
