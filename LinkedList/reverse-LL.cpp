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

//***********************************

void reverse_itr_1(ListNode *&head)
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

void reverse_itr_2(ListNode **head)
{
    ListNode *curr = *head;
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

ListNode *reverse_itr_3(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *next;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
//*************************************

ListNode *reverse_rec_1(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *temp = head;
    ListNode *sub_head = reverse_rec_1(temp->next);
    head->next->next = temp;
    temp->next = nullptr;

    return sub_head;
}

void reverseUtil(ListNode *curr, ListNode *prev, ListNode **head)
{
    if (curr->next == nullptr)
    {
        *head = curr;
        curr->next = prev;
        return;
    }
    ListNode *next = curr->next;
    curr->next = prev;

    reverseUtil(next, curr, head);
}

void reverse_rec_2(ListNode **head)
{
    if (head == nullptr || *head == nullptr)
        return;
    reverseUtil(*head, nullptr, head);
}


//******************************************
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
    ListNode *head=dummy->next;

    reverse_itr_1(head);
    // reverse_itr_2(&head);
    // head = reverse_itr_3(head);
    // head = reverse_rec_1(head);
    // reverse_rec_2(&head);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}