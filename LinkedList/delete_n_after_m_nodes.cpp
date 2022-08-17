//https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1#
class Solution
{
    public:
    
    void deleteMLL(Node* prev, int n)
    {
        int count=0;
        Node* curr=prev->next;
        while(curr!=NULL && count<n)
        {
            Node* temp=curr;
            curr= curr->next;
            delete temp;
            
            count++;
        }
        prev->next=curr;
    }
    void linkdelete(struct Node  *head, int m, int n)
    {
        Node* curr=head;
        while(curr!=NULL)
        {
            int count=1;
            while(curr!=NULL && count<m)
            {
                curr=curr->next;
                count++;
            }
            if(curr==NULL)
                return;
            deleteMLL(curr, n);
            curr=curr->next;
        }        
    }
};
