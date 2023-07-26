// Solution is for Leetcode

// 1 Validate BST

class Solution {
public:
    bool solve(TreeNode* root, long long min, long long max){
        if(root == NULL){
            return true;
        }

        if(root->val > min && root->val < max){
            bool left = solve(root->left, min, root->val);
            bool right = solve(root->right, root->val , max);
            return left && right;
        }else{
            return false;
        }

    }
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};


// 3 Kth Smallest/Largest in BST

class Solution {
public:
    int K;
    void Recursion(TreeNode* root, int& count, int& value){
        if(!root)
            return;
        
        Recursion(root->left, count, value);
        count++;
        if(count==K)
            value = root->val;
        Recursion(root->right, count, value);

    }

    int kthSmallest(TreeNode* root, int k) {

        int value = -1;
        K=k;
        int count = 0;
        Recursion(root,count , value);
        return value;
    }
}

// 4 LCA in BST

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root)
        return NULL;
    
    if(root->val > p->val and root->val > q->val){
        root = lowestCommonAncestor(root->left, p, q);
    }

    if(root->val < p->val and root->val < q->val){
        root = lowestCommonAncestor(root->right, p, q);
    }
    
    return root;

}
