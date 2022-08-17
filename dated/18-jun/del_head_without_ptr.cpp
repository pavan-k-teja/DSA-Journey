//https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1

void deleteNode(Node *del)
{
    // Your code here
    Node* temp=del->next;
    del->data = temp ->data;
    del->next = temp->next;
    delete temp;
    
}