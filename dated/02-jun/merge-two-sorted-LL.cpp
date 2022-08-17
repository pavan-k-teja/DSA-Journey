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

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1==nullptr)
        return l2;

    if(l2==nullptr)
        return l1;

    ListNode *dummy = new ListNode(-1);
    ListNode *result = dummy;
    ListNode *last = dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
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
    
    result=result->next;
    dummy->next=nullptr;
    delete dummy;

    return result;
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
    int n, m;
    cin >> n;
    ListNode *h1 = createList(n);
    cin >> m;
    ListNode *h2 = createList(m);

    ListNode *head = mergeTwoLists(h1, h2);
    printList(head);

    return 0;
}