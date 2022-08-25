#include <bits/stdc++.h>
using namespace std;
vector<int>::iterator it;
#define ll long long

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildtree(node *root)
{

    cout << "Enter the data : " << endl;
    int datas;
    cin >> datas;
    root = new node(datas);

    if (datas == -1)
        return NULL;

    cout << "Enter the left data of " << datas << endl;
    root->left = buildtree(root->left);

    cout << "Enter the right data of " << datas << endl;
    root->right = buildtree(root->right);
    return root;
}

void buildbylevelOrderofTraversal(node *&root)
{

    queue<node *> q;
    int data;
    cout << "Enter the root data : ";
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {

        node *temp = q.front();
        q.pop();

        cout << "Enter the left data of " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter the right data of " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void LevelOrderofTraversal(node *root)
{

    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {

            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }
    }
}

void ReverseLevelOrderofTraversal(node *root)
{

    queue<node *> q;
    vector<int> ans;
    q.push(root);
   
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        if (temp->right)
            q.push(temp->right);

        if (temp->left)
            q.push(temp->left);
    }

    reverse(ans.begin(), ans.end());

    for (auto i : ans)
    {
        cout << i << " ";
    }
}

void inOrder(node *root)
{

    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node *root)
{

    if (root == NULL)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node *root)
{

    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // 1 3 5 7  11 17 -1 -1 -1 -1 -1 -1 -1
    /*root = buildtree(root);

    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << "\nLevel order of traversal" << endl;
    */
   
    buildbylevelOrderofTraversal(root);

    cout << "Time to traverse : " << endl;
    LevelOrderofTraversal(root);

    cout << "\nReverse traversal of root" << endl;

    ReverseLevelOrderofTraversal(root);

    return 0;
}