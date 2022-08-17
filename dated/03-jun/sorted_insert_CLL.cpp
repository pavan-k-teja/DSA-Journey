//https://practice.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

class Solution
{
    public:
    
    void swap(int &x, int &y)
    {
        int temp=x;
        x=y;
        y=temp;
    }
    Node *sortedInsert(Node* head, int data)
    {
        Node* new_node = new Node(data);
        Node* current = head;
        if (current == NULL) 
        { 
            new_node->next = new_node; 
            return new_node; 
        } 
        
        else if(data < head->data)
        {
            swap(head->data, new_node->data);
            new_node->next = head->next;
            head->next=new_node;
            return head;
        }
        
        else
        {
            while (current->next!= head && current->next->data < new_node->data) 
                current = current->next; 
          
            new_node->next = current->next; 
            current->next = new_node;
            
            return head;
        }
       
       
       
    }
 
};