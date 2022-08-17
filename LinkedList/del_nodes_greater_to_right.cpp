class Solution
{
    void reverse(Node* &head)
    {
        Node *curr = head;
        Node *prev = nullptr;
        Node *next = nullptr;
    
        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(head == nullptr || head->next == nullptr)
            return head;
        
        reverse(head);
        Node* curr = head;
        while(curr!=nullptr && curr->next!=nullptr)
        {
            while(curr->next!=nullptr && curr->next->data < curr->data)
            {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            curr = curr->next;
        }
        
        reverse(head);
        return head;
    }
    
};