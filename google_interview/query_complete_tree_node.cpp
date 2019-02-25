complete tree， 提供query 数字，找到对应的node, logN找到path  蠡口里面的


void getPath(int n, vector<string>& path)
{
    if(n == 0)
        return;
    if((n-2)%2 == 0)
    {
        path.push_back("right");
        getPath((n-2)/2, path);
    }
    else
    {
        path.push_back("left");
        getPath((n-1)/2, path);
    }
}

TreeNode* getCompleteTreeNode(TreeNode* root, int idx)
{
    if(!root)
        return NULL;
    vector<string> path;
    getPath(idx, path);
    reverse(path.begin(), path.end());
    TreeNode* travel = root;
    int i = 0;
    while(i < path.size())
    {
        if(path[i] == "left")
            travel = travel->left;
        else
            travel = travel->right;
        if(travel == NULL)
            return NULL;
        ++i;
    }
    return travel;
}
