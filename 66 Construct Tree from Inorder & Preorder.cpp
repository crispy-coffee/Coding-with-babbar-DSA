//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    void creatmap(int in[], map<int,int> &mappings, int n){
        for(int i=0; i<n; i++)
            mappings[in[i]] = i;
    }
    
    Node* solve(int in[], int pre[], int &index, int start, int end, int n, map<int,int> &mappings){
        
        if(index>=n || start>end)
            return NULL;
            
        int element = pre[index++];
        Node* root = new Node(element);
        int position = mappings[element];
        
        root->left = solve(in, pre, index, start, position-1, n, mappings);
        root->right = solve(in, pre, index, position+1, end, n, mappings);
        
        return root;
        
        
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {   
        int index = 0;
        map<int,int> mappings;
        creatmap(in, mappings, n);
        Node *ans = solve(in, pre, index,0, n-1, n, mappings);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends