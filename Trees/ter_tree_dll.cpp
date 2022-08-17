// C++ program to create a doubly linked list out
// of given a ternary tree.
#include <bits/stdc++.h>
using namespace std;

/* A ternary tree */
struct Node
{
	int data;
	struct Node *left, *middle, *right;
};

/* Helper function that allocates a new node with the
given data and assign NULL to left, middle and right
pointers.*/
Node* newNode(int data)
{
	Node* node = new Node;
	node->data = data;
	node->left = node->middle = node->right = NULL;
	return node;
}

/* Utility function that constructs doubly linked list
by inserting current node at the end of the doubly
linked list by using a tail pointer */
void push(Node** tail_ref, Node* node)
{
	// initialize tail pointer
	if (*tail_ref == NULL)
	{
		*tail_ref = node;

		// set left, middle and right child to point
		// to NULL
		node->left = node->middle = node->right = NULL;

		return;
	}

	// insert node in the end using tail pointer
	(*tail_ref)->right = node;

	// set prev of node
	node->left = (*tail_ref);

	// set middle and right child to point to NULL
	node->right = node->middle = NULL;

	// now tail pointer will point to inserted node
	(*tail_ref) = node;
}

/* Create a doubly linked list out of given a ternary tree.
by traversing the tree in preorder fashion. */
void TernaryTreeToList(Node* root, Node** head_ref)
{
    if(root==nullptr)
        return;

    
    *head_ref = root;
    
    Node* left=nullptr;
    TernaryTreeToList(root->left, &left);

    Node* right;
}

// Utility function for printing double linked list.
void printList(Node* head)
{
	printf("Created Double Linked list is:\n");
	while (head)
	{
		printf("%d ", head->data);
		head = head->right;
	}
}

// Driver program to test above functions
int main()
{
	// Constructing ternary tree as shown in above figure
	Node* root = newNode(30);

	root->left = newNode(5);
	root->middle = newNode(11);
	root->right = newNode(63);

	root->left->left = newNode(1);
	root->left->middle = newNode(4);
	root->left->right = newNode(8);

	root->middle->left = newNode(6);
	root->middle->middle = newNode(7);
	root->middle->right = newNode(15);

	root->right->left = newNode(31);
	root->right->middle = newNode(55);
	root->right->right = newNode(65);

	Node* head = NULL;

	TernaryTreeToList(root, &head);

	printList(head);

	return 0;
}
