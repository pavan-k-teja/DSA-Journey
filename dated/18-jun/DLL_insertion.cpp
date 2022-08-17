//https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1

void addNode(struct Node *head, int pos, int data)
{
    Node* curr=head;
    int count=0;
    while(curr!=NULL && count<pos)
    {
        curr=curr->next;
        count++;
    }
    if(curr==NULL)
        return;
    Node* node= new Node(data);
    
    node->next = curr->next;
    curr->next = node;
    node->prev=curr;
    
    if(node->next!=NULL)
        node->next->prev=node;
}