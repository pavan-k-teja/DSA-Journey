//https://practice.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *reverse_LL(Node *head)
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
    return prev;
}

Node *mergeTwoLists(Node *l1, Node *l2)
{
    if (l1 == nullptr)
        return l2;

    if (l2 == nullptr)
        return l1;

    Node *dummy = new Node(-1);
    Node *result = dummy;
    Node *last = dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->data < l2->data)
        {
            last->next = l1;
            last = l1;
            l1 = l1->next;
        }
        else
        {
            last->next = l2;
            last = l2;
            l2 = l2->next;
        }
    }
    if (l1 != nullptr)
        last->next = l1;
    if (l2 != nullptr)
        last->next = l2;

    result = result->next;
    dummy->next = nullptr;
    delete dummy;

    return result;
}

void sort(Node **head_ptr)
{
    if ((*head_ptr) == nullptr || (*head_ptr)->next == nullptr)
        return;

    Node *dummy1 = new Node(-1);
    Node *last1 = dummy1;
    Node *dummy2 = new Node(-1);
    Node *last2 = dummy2;

    Node *curr = *head_ptr;
    int count = 0;
    while (curr != nullptr)
    {
        if (count % 2 == 0)
        {
            last1->next = curr;
            last1 = last1->next;
        }
        else
        {
            last2->next = curr;
            last2 = last2->next;
        }
        curr = curr->next;
        count++;
    }

    last1->next = nullptr;
    last2->next = nullptr;

    if (dummy2->next != nullptr)
        dummy2->next = reverse_LL(dummy2->next);

    *head_ptr = mergeTwoLists(dummy1->next, dummy2->next);
}