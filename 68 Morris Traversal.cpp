#include <bits/stdc++.h>
using namespace std;

/* A binary tree tNode has data, a pointer to left child
and a pointer to right child */
struct tNode
{
	int data;
	struct tNode *left;
	struct tNode *right;
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(struct tNode *root)
{
	tNode *curr = root;
	tNode *pred;

	if (root == NULL)
		return;
	while (curr != NULL)
	{

		if (curr->left == NULL)
		{

			cout << "1. Data " << curr->data << endl;
			curr = curr->right;
		}
		else
		{
			pred = curr->left;
			while (pred->right != NULL && pred->right != curr)
				pred = pred->right;

			if (pred->right == NULL)
			{
				pred->right = curr;
				curr = curr->left;
			}
			else
			{
				pred->right = NULL;
				cout << "2. Data " << curr->data << endl;
				curr = curr->right;
			}
		}
	}
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new tNode with the
given data and NULL left and right pointers. */
struct tNode *newtNode(int data)
{
	struct tNode *node = new tNode;
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
			1
		/ \
		2	 3
	/ \
	4	 5
*/
	struct tNode *root = newtNode(1);
	root->left = newtNode(2);
	root->right = newtNode(3);
	root->left->left = newtNode(4);
	root->left->right = newtNode(5);

	MorrisTraversal(root);

	return 0;
}

// This code is contributed by Sania Kumari Gupta (kriSania804)
