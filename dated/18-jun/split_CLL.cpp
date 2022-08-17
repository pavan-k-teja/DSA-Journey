//https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if (head->next == head)
    {
        *head1_ref = nullptr;
        *head2_ref = head;
        return;
    }
    
    if(head->next->next == head)
    {
        *head1_ref = head;
        *head2_ref = head->next;
       (*head1_ref)->next = *head1_ref;
       (*head2_ref)->next = *head2_ref;
       return;
    }
    
    Node *slow = head, *fast = head;
    while(fast->next != head && fast->next->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    *head1_ref = head;
    *head2_ref = slow->next;
    
    slow->next = head;
    
    Node *curr = *head2_ref;
    while(curr->next != head)
        curr=curr->next;
    
    curr->next = *head2_ref;

}
void push(Node **head_ref, int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;
    if (*head_ref != NULL)
    {
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;
    *head_ref = ptr1;
}
void printList(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        cout << endl;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}
int main()
{
    int list_size, i;
    Node *head = NULL;
    Node *head1 = NULL;
    Node *head2 = NULL;
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);
    cout << "Original Circular Linked List";
    printList(head);
    splitList(head, &head1, &head2);
    cout << "\nFirst Circular Linked List";
    printList(head1);
    cout << "\nSecond Circular Linked List";
    printList(head2);
    return 0;
}
