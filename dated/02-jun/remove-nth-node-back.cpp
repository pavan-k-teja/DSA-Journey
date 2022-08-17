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

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *first = head;
    int count = 1;
    while (first->next != nullptr && count != n)
    {
        first = first->next;
        count++;
    }
    if (first->next == nullptr)
    {
        ListNode *first = head->next;
        delete head;
        return first;
    }

    ListNode *second = head;
    ListNode *prev = head;
    while (first->next != nullptr)
    {
        first = first->next;
        prev = second;
        second = second->next;
    }
    prev->next = second->next;
    delete second;

    return head;
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

ListNode *createList(int n)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prev = dummy;
    while (n-- > 0)
    {
        int val;
        cin >> val;
        prev->next = new ListNode(val);
        prev = prev->next;
    }
    return dummy->next;
}

int main()
{
    int n;
    cin >> n;
    ListNode *h1 = createList(n);
    int m;
    cin >> m;
    h1 = removeNthFromEnd(h1, m);
    printList(h1);

    return 0;
}