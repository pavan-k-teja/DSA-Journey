//https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1

Node* insertInMiddle(Node* head, int x)
{
	// Cpde here
	Node* slow=head;
    Node* fast= head->next;
    
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* node = new Node(x);
    node->next=slow->next;
    slow->next=node;
    
    return head;
}