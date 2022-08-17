//https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

class Solution
{
    public:
    Node* deleteNode(Node *head_ref, int x)
    {
      //Your code here
        if(x == 1)
        {
            Node* temp = head_ref->next;
            temp->prev = NULL;
            delete head_ref;
            return temp;
        }
        int count = 2;
        Node* curr = head_ref;
        
        while(curr!=NULL && count<x)
        {
            curr = curr->next;
            count++;
        }
        if(curr ==NULL)
            return head_ref;
        
        Node* temp = curr->next;
        curr->next = temp->next;
    
        if(temp->next!=NULL)
            temp->next->prev = curr;
        
        delete temp;
        return head_ref;
    }
};