//https://practice.geeksforgeeks.org/problems/split-singly-linked-list-alternatingly/1

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
struct Node *a;
struct Node *b;

void alternatingSplitList(struct Node *head)
{
    if ((head) == nullptr || (head)->next == nullptr)
    {
        a = head;
        b = nullptr;
        return;
    }

    Node *dummy1 = new Node(-1);
    Node *last1 = dummy1;
    Node *dummy2 = new Node(-1);
    Node *last2 = dummy2;

    Node *curr = head;
    bool count = 0;
    while (curr != nullptr)
    {
        if (count == 0)
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
        count = !count;
    }

    last1->next = nullptr;
    last2->next = nullptr;

    a = dummy1->next;
    b = dummy2->next;

    return;
}