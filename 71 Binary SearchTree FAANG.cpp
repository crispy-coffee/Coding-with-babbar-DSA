// Questions are as per the Leetcode

// 1 Normal BST to Balanced BST

class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*> &in){
        if(!root)
        return ;

        inorder(root->left, in);
        in.push_back(root);
        inorder(root->right, in);
    }

    TreeNode* balancing(int start, int end, vector<TreeNode*> &in){
        if(start>end) return NULL;

        int mid = (start+end)/2;
        in[mid]->left = balancing(start, mid-1, in);
        in[mid]->right = balancing(mid+1, end, in);
        return in[mid];
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> in;
        inorder(root, in);
        return balancing(0,in.size()-1, in);
    }
};


// 2 BST from Preorder
class Solution {
public:
    TreeNode* solve(int mini, int maxi, vector<int> &in, int &i){
        if(i>=in.size()) 
            return NULL;
        if(in[i]<mini || in[i]>maxi) 
            return NULL;

        TreeNode* root = new TreeNode(in[i++]);

        root->left = solve(mini,root->val, in, i);
        root->right = solve(root->val, maxi, in, i);
        return root;       
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return solve(INT_MIN, INT_MAX, preorder, i);
    }
};

// 3 Flatten BST to Sorted LL
class Solution {
public:
    void invector(TreeNode* root, vector<TreeNode*> &in){
        if(!root) return;
        in.push_back(root);
        invector(root->left, in);
        invector(root->right, in);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> in;
        invector(root, in);
        int i;
        for(i=1; i<in.size(); i++){
            in[i-1]->right = in[i];
            in[i-1]->left = NULL;
            if(i==in.size()-1){
                in[i]->right = NULL;
                in[i]->left = NULL;
            }
        }   
    }
};

// 4 Two Sum in BST
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &in){
        if(!root)
        return ;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root, in);

        int i=0, j=in.size()-1;

        while(i<j){
            if(in[i]+in[j]==k)
                return true;
            else if(in[i]+in[j]<k)
                i++;
            else
                j--;
        }

        return false;
    }
};


