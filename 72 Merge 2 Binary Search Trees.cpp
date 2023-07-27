// Approach 1

void inorder(TreeNode<int>* root, vector<int>& v){
    if(root == NULL)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

TreeNode<int>* createBST(int start, int end, vector<int>& v){
    if(start>end)
        return NULL;

    int mid = start + (end-start)/2;
    TreeNode<int>* root = new TreeNode<int>(v[mid]);

    root->left = createBST(start, mid-1, v);
    root->right = createBST(mid+1, end, v);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> v;
    inorder(root1, v);
    inorder(root2, v);
    sort(v.begin(), v.end());

    return createBST(0, v.size()-1, v);
}

