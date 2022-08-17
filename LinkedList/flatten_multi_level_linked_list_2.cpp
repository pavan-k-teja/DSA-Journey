// C++ program to flatten a multilevel linked list
#include <bits/stdc++.h>
using namespace std;

// A Linked List Node
struct Node
{
	int data;
	struct Node *next;
	struct Node *down;
};

// Flattens a multi-level linked list depth wise
Node* flattenList(Node* node)
{
	// Base case
  if (node == NULL)
      return NULL;

  Node* curr = node;

  Node* nxt = flattenList(curr->next);
  curr->next = flattenList(curr->down);
  
  while(curr->next!=nullptr)
    curr = curr->next;
  curr->next = nxt;
  
  return node;
}

// Utility method to print a linked list
void printFlattenNodes(Node* head)
{
	while (head)
	{
	printf("%d ", head->data);
	head = head->next;
	}
	
}

// Utility function to create a new node
Node* newNode(int new_data)
{
	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = new_node->down = NULL;
	return new_node;
}

// Driver code
int main()
{
	// Creating above example list
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->down = newNode(7);
	head->next->down->down = newNode(9);
	head->next->down->down->down = newNode(14);
	head->next->down->down->down->down
									= newNode(15);
	head->next->down->down->down->down->next
									= newNode(23);
	head->next->down->down->down->down->next->down
									= newNode(24);
	head->next->down->next = newNode(8);
	head->next->down->next->down = newNode(16);
	head->next->down->next->down->down = newNode(17);
	head->next->down->next->down->down->next
									= newNode(18);
	head->next->down->next->down->down->next->next
									= newNode(19);
	head->next->down->next->down->down->next->next->next
									= newNode(20);
	head->next->down->next->down->down->next->next->next->down
									= newNode(21);
	head->next->down->next->next = newNode(10);
	head->next->down->next->next->down = newNode(11);

	head->next->down->next->next->next = newNode(12);

	// Flatten list and print modified list
	head = flattenList(head);
	printFlattenNodes(head);

	return 0;
}
	