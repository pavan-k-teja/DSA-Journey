/*
Given a singly linklist with an additional random pointer which could point to any node in the list or NULL.
Return a deep copy of the list.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ListNode
{
public:
    int val = 0;
    ListNode *next = nullptr;
    ListNode *random = nullptr;

    ListNode(int val)
    {
        this->val = val;
    }
};

ListNode *copyRandomList_1(ListNode *head)
{
    //method 1: make hashmap with corresponding addresses,
    //TC=O(n) SC=O(n)
    if (head == nullptr)
        return nullptr;
    if (head->next == nullptr)
        return new ListNode(head->val);

    ListNode *newHead = new ListNode(-1);
    ListNode *newEnd = newHead;
    ListNode *curr = head;

    unordered_map<ListNode *, ListNode *> um;
    while (curr != nullptr)
    {
        newEnd->next = new ListNode(curr->val);
        newEnd = newEnd->next;
        um[curr] = newEnd;
        curr = curr->next;
    }

    ListNode *curr1 = head;
    ListNode *curr2 = newHead->next;
    while (curr1 != nullptr && curr2 != nullptr)
    {
        ListNode *temp = (curr1->random != nullptr) ? um[curr1->random] : nullptr;

        curr2->random = temp;

        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return newHead->next;
}

//**********************************************
void copyList(ListNode *head)
{
    ListNode *curr = head;

    while (curr != nullptr)
    {
        ListNode *next = curr->next;
        ListNode *temp = new ListNode(curr->val);
        curr->next = temp;
        temp->next = next;

        curr = next;
    }
}

void copyRandomPtrs(ListNode *head)
{
    ListNode *curr1 = head;

    while (curr1 != nullptr)
    {
        ListNode *temp = (curr1->random != nullptr) ? curr1->random->next : nullptr;

        curr1->next->random = temp;
        curr1 = curr1->next->next;
    }
}
ListNode *extractListNode(ListNode *head)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr != nullptr)
    {
        prev->next = curr->next;
        curr->next = curr->next->next;

        prev = prev->next;
        curr = curr->next;
    }

    return dummy->next;
}

ListNode *copyRandomList_2(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    copyList(head);

    copyRandomPtrs(head);

    return extractListNode(head);
}

int main()
{
    int n;
    cin >> n;

    vector<ListNode *> arr(n);
    ListNode *prev = nullptr;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ListNode(0);
        if (prev != nullptr)
            prev->next = arr[i];
        prev = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int val, idx;
        cin >> val >> idx;

        arr[i]->val = val;
        if (idx != -1)
            arr[i]->random = arr[idx];
    }

    ListNode *head = copyRandomList_2(arr[0]);
    while (head != nullptr)
    {
        cout << "(" + to_string(head->val) + ", " + (head->random != nullptr ? to_string(head->random->val) : to_string(-1)) + ") ";
        head = head->next;
    }
    return 0;
}