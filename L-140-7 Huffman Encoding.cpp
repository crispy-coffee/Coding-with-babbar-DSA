class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

void traversal(Node* root, string temp, vector<string>& result){
    if(root->left == NULL and root->right == NULL){
        result.push_back(temp);
        return;
    }
    
    traversal(root->left, temp+'0', result);
    traversal(root->right, temp+'1', result);
}

class Solution
{
	public:
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
	    priority_queue<Node*, vector<Node*>, cmp> pq;
	    
	    for(int i=0; i<N; i++){
	        pq.push(new Node(f[i]));
	    }
	    
	    while(pq.size() > 1){
	        Node* left = pq.top();
	        pq.pop();
	        
	        Node* right = pq.top();
	        pq.pop();
	        
	        Node* merged = new Node(left->data + right->data);
	        merged->left = left;
	        merged->right = right;
	        
	        pq.push(merged);
	    }
	    
	    vector<string> result;
	    traversal(pq.top(), "", result);
	    return result;
	    
	}
};