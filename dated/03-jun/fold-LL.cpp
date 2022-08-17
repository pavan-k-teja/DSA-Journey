/*
Fold a given Linked List. To fold a linked list we have to first create a simple linked list. When we fold a linked list it will take place between the nodes.  We can say that at every step we change the next of the left node such that it points to the right node. the next of a right node also change accordingly.

Program for folding a given Linked List . Example:

Given Linked list : 1–>2–>3–>4–>5–>6

Output of the given linked list after folding

1–>6–>2–>5–>3–>4
*/

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *midNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

void reverse_LL(ListNode *&head)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void fold(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return;
    ListNode *mid = midNode(head);
    ListNode *subHead = mid->next;
    mid->next=nullptr;
    reverse_LL(subHead);

    ListNode *curr1 = head;
    ListNode *curr2 = subHead;
    ListNode *next1 = curr1->next;
    ListNode *next2 = curr2->next;

    while (curr1 != nullptr && curr2 != nullptr)
    {
        next1 = curr1->next;
        next2 = curr2->next;

        curr1->next = curr2;
        curr2->next = next1;

        curr1 = next1;
        curr2 = next2;
    }
}

void printList(ListNode *node)
{
    ListNode *curr = node;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }

    ListNode *head = dummy->next;
    fold(head);
    printList(head);

    return 0;
}