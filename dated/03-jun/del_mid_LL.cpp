/*
https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
int countOfNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->next;
        count++;
    }
    return count;
}
struct Node* deleteMid(Node* head)
{
    if(head==NULL || head->next == NULL)
        return NULL;
    
    if(head->next->next==NULL)
    {
        head->next=NULL;
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;
    Node* prev;
    while(fast!=NULL && fast->next!=NULL)
    {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast==NULL)
    {
        Node* temp=slow;
        prev->next=slow->next;
        delete temp;
        return head;    
    }
    else
    {
        Node* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
    }
    return head;
    
}
void printList(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL\n";
}
Node *newNode(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int main()
{
    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    cout << "Given Linked List\n";
    printList(head);
    head = deleteMid(head);
    cout << "Linked List after deletion of middle\n";
    printList(head);
    return 0;
}
