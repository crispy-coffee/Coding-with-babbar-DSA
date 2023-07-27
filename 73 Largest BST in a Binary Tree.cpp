class info{
public:
    int mini;
    int maxi;
    int size;
    bool isBST;
};

info Recursion(TreeNode<int>* root, int& ans){
    if(!root){
        return {INT_MAX, INT_MIN, 0, true};
    }

    info left = Recursion(root->left, ans);
    info right = Recursion(root->right, ans);

    info curr;
    curr.mini = min(root->data, left.mini);
    curr.maxi = max(root->data, right.maxi);
    curr.size = left.size + right.size + 1;

    if(left.isBST and right.isBST and left.maxi < root->data and root->data < right.mini){
        curr.isBST = true;
    }else{
        curr.isBST = false;
    }

    if(curr.isBST){
        ans = max(ans, curr.size);
    }
    return curr;
}

int largestBST(TreeNode<int>* root) 
{   
    int maxsize = 0;
    info temp = Recursion(root, maxsize);
    return maxsize;
}