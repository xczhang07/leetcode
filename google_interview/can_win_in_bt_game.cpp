struct ParentTreeNode
{
	ParentTreeNode* left;
	ParentTreeNode* right;
	ParentTreeNode* parent;
	int val;
	ParentTreeNode(int value)
	{
		this->val = value;
		this->left = NULL;
		this->right = NULL;
		this->parent = NULL;
	}
};

void countSubTreeNode(ParentTreeNode* node, int& cnt)
{
	if (node == NULL)
		return;
	cnt++;
	countSubTreeNode(node->left, cnt);
	countSubTreeNode(node->right, cnt);
	return;
}

void countParentTreeNode(ParentTreeNode* node, int& cnt, ParentTreeNode* parent)
{
	if (parent == NULL)
		return;
	cnt++;
	if (parent->left == node)
		countSubTreeNode(parent->right, cnt);
	else
		countSubTreeNode(parent->left, cnt);
	node = node->parent;
	countParentTreeNode(node, cnt, node->parent);
}

bool findParent(ParentTreeNode* root, ParentTreeNode* node)
{
	if (root == NULL)
		return false;
	if (node == NULL)
		return true;
	int l = 0, r = 0, p = 0;
	countSubTreeNode(node->left, l);
	countSubTreeNode(node->right, r);
	countParentTreeNode(node, p, node->parent);
	if (l == r && l == p)
		return false;
	else if (l > r + 1 || r > l + 1 || p > l + 1 || p > r + 1)
		return true;
	else
		return false;
}


int main()
{
ParentTreeNode* pNode1 = new ParentTreeNode(1);
	ParentTreeNode* pNode2 = new ParentTreeNode(2);
	ParentTreeNode* pNode3 = new ParentTreeNode(3);
	ParentTreeNode* pNode4 = new ParentTreeNode(4);
	ParentTreeNode* pNode5 = new ParentTreeNode(5);
	ParentTreeNode* pNode6 = new ParentTreeNode(6);
	ParentTreeNode* pNode7 = new ParentTreeNode(7);
	ParentTreeNode* pNode8 = new ParentTreeNode(8);
	ParentTreeNode* pNode0 = new ParentTreeNode(0);
	ParentTreeNode* pNode9 = new ParentTreeNode(9);

	pNode0->left = pNode1;
	pNode1->parent = pNode0;
	pNode1->left = pNode2;
	pNode2->left = pNode4;
	pNode2->right = pNode5;
	pNode4->left = pNode8;
	pNode1->right = pNode3;
	pNode3->left = pNode6;
	pNode3->right = pNode7;
	pNode2->parent = pNode1;
	pNode3->parent = pNode1;
	pNode4->parent = pNode2;
	pNode5->parent = pNode2;
	pNode8->parent = pNode4;
	pNode3->parent = pNode1;
	pNode6->parent = pNode3;
	pNode7->parent = pNode3;
	pNode0->right = pNode9;
	pNode9->parent = pNode0;

	if (findParent(pNode1, pNode2))
		cout << "yes, you can win" << endl;
	else
		cout << "sorry, you lost it" << endl;

  return 0;
}
