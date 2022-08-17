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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;

    reverse_LL(l1);
    reverse_LL(l2);

    ListNode *result = new ListNode(-1);
    ListNode *curr = result;

    int carry = 0;
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int var1 = l1 != nullptr ? l1->val : 0;
        int var2 = l2 != nullptr ? l2->val : 0;

        int sum = carry + var1 + var2;

        carry = sum / 10;
        sum = sum % 10;

        curr->next = new ListNode(sum);
        curr = curr->next;

        if (l1 != nullptr)
            l1 = l1->next;
        if (l2 != nullptr)
            l2 = l2->next;
    }

    reverse_LL(l1);
    reverse_LL(l2);

    reverse_LL(result->next);
    return result->next;
}


ListNode *makeList(int n)
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
    ListNode *head1 = makeList(n);

    int m;
    cin >> m;
    ListNode *head2 = makeList(m);

    ListNode *head = addTwoNumbers(head1, head2);
    printList(head);

    return 0;
}