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

ListNode *mulLLwithDigit(ListNode* head, int digit)
{
    ListNode* dummy = new ListNode(0);
    if(digit==0)
        return dummy;
    ListNode* curr= head;
    ListNode* ans_curr= dummy;
    int carry = 0;

    while(curr!=nullptr || carry!=0)
    {
        int prod = carry + ((curr!=nullptr)? curr->val: 0) *digit;

        int digit = prod%10;
        carry = prod/10; 

        ans_curr->next=new ListNode(digit);

        if(curr!=nullptr)
            curr=curr->next;
        ans_curr=ans_curr->next;
    }
    return dummy->next;
    
}

void addTwoLL(ListNode* head, ListNode* ansItr)
{
    ListNode* c1 = head;
    ListNode* c2 = ansItr;

    int carry=0;
    while(c1 !=nullptr || carry!=0)
    {
        int sum = carry + (c1!=nullptr ? c1->val : 0) + (c2->next !=nullptr ? c2->next->val : 0);

        int digit = sum%10;
        carry = sum/10;


        if(c2->next !=nullptr)
            c2->next->val = digit;
        else
            c2->next = new ListNode(digit);
        if(c1 != nullptr)
            c1 = c1->next;
        c2 = c2->next;
    }

    
}

ListNode *mulTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr || l2 == nullptr)
        return new ListNode(0);

    reverse_LL(l1);
    reverse_LL(l2);

    ListNode* l2_itr = l2;
    ListNode* dummy = new ListNode(-1);
    ListNode* ansItr = dummy;
    while(l2_itr!=nullptr)
    {
        ListNode *prod = mulLLwithDigit(l1, l2_itr->val);
        l2_itr = l2_itr->next;

        addTwoLL(prod, ansItr);
        ansItr=ansItr->next;

    }

    reverse_LL(dummy->next);
    return dummy->next;
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

    ListNode *head = mulTwoNumbers(head1, head2);
    printList(head);

    return 0;
}