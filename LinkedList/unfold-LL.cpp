/*
A linked list L0 -> L1 -> L2 -> ….. -> LN can be folded as L0 -> LN -> L1 -> LN – 1 -> L2 -> ….. 
Given a folded linked list, the task is to unfold and print the original linked list

Examples:  

Input: 1 -> 6 -> 2 -> 5 -> 3 -> 4 
Output: 1 2 3 4 5 6

Input: 1 -> 5 -> 2 -> 4 -> 3 
Output: 1 2 3 4 5 
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


void unfold(ListNode *head)
{
    if(head==nullptr || head->next==nullptr)
        return;

    ListNode* first=head;
    ListNode* second=head->next;

    ListNode* firstEnd=head;
    ListNode* secondEnd=head->next;

    int count=0;
    ListNode* curr=head->next->next;

    while(curr!=nullptr)
    {
        if(count%2==0)
        {
            firstEnd->next=curr;
            firstEnd=firstEnd->next;    
        }
        else
        {
            secondEnd->next=curr;
            secondEnd=secondEnd->next;    
        }
        curr=curr->next;
        count++;
    }
    firstEnd->next=nullptr;
    secondEnd->next=nullptr;

    reverse_LL(second);

    firstEnd->next=second;

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
    unfold(head);
    printList(head);

    return 0;
}