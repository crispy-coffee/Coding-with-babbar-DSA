#include<bits/stdc++.h>
using namespace std;
#define ll long long

class node{

    public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

node* buildtree(node* root){

   
    cout << "Enter the data : " << endl;
    int datas;
    cin >> datas;
    root = new node(datas);

    if(datas ==-1)
        return NULL;
    
    cout << "Enter the left data of " << datas << endl;
    root->left = buildtree(root->left);
    
    cout << "Enter the right data of " << datas << endl;
    root->right = buildtree(root->right);
    return root;
}

void inOrder(node* root){

    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);

}

int main(){

    node* root = NULL;

    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    root = buildtree(root);
    
    inOrder(root);

return 0;
}