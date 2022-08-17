//https://practice.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

void deleteNode(Node** head, int key) 
{
    if (*head == NULL)
        return;
          
    if((*head)->data==key && (*head)->next==*head)
    {
        delete (*head);
        *head=NULL;
        return;
    }
      
    Node *last=*head,*temp;
      
    if((*head)->data==key) 
    {
        while(last->next!=(*head))
            last=last->next;
              
        last->next=(*head)->next;
        delete (*head);
        (*head)=last->next;
        return;
    }
      
    while(last->next!=(*head) && last->next->data!=key) 
        last=last->next;
      
    if(last->next->data==key) 
    {
        temp=last->next;
        last->next=temp->next;
        delete (temp);
    }
    
}
/* Function to reverse the linked list */

void reverse(Node** head_ref)
{
    if (*head_ref == NULL)
        return;
  
    Node* prev = NULL;
    Node* current = (*head_ref);
    Node* next = current;
    
    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }while (current != (*head_ref));
    
    (*head_ref)->next = prev;
    *head_ref = prev;
}