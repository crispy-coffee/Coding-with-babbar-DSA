#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void insert(Node *&root, int d)
{

    if (root == NULL)
    {
        root = new Node(d);
        return ;
    }

    if (root->data < d)
        insert(root->right, d);
    else
        insert(root->left, d);
}

void takeinput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        insert(root, data);
        cin >> data;
    }
}

void inorder(Node *root)
{
    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(Node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node *root)
{

    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void maxvalue(Node* root){

    Node* temp = root;
    while(temp->right!= NULL){
        temp = temp->right;
    }
    cout <<"Max value : " << temp->data << endl;

}

void minvalue(Node* root){

    Node* temp = root;
    while(temp->left!= NULL){
        temp = temp->left;
    }
    cout <<"Min value : " << temp->data << endl;

}

bool search(Node*root, int k){
    
    if(!root)
    return false;
    
    if(root->data == k)
    return true;


    if(root->data > k)
    return search(root->left, k);
    else
    return search(root->right, k);
}

//for min value from right node 
Node* minval(Node* root){
    while(root->left != NULL)
    root = root->left;

    return root;
}

Node* deletefrombst(Node* root, int k){

    if(root == NULL)
        return NULL;

    if(root->data == k){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;

              //1 child

              //left chile is not NULL
        }else if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;

            //right child is not NULL
        }else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;

            //root has 2 child
        }else if(root->left != NULL && root->right != NULL){
            int mini = minval(root->right) ->data;
            root->data = mini;
            root->right = deletefrombst(root->right, mini);
            return root;
        }

    }else if(root->data > k){
        root->left = deletefrombst(root->left, k);
    }else
        root->right = deletefrombst(root->right, k);


    return root;

}

int main()
{

    Node *root = NULL;

    takeinput(root);

    cout << "Inorder start" << endl;
    inorder(root);

    minvalue(root);
    maxvalue(root);

    cout << search(root, 80) << endl;

    root = deletefrombst(root, 50);

    inorder(root);

    return 0;
}