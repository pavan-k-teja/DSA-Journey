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

ListNode *segregateEvenOdd(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* evenHead=nullptr;
    ListNode* oddHead=nullptr;
    ListNode* evenEnd=nullptr;
    ListNode* oddEnd=nullptr;
    
    ListNode* curr=head;
    
    while(curr!=nullptr)
    {
        if(curr->val %2==1)
        {
            if(oddHead==nullptr)
                oddHead=oddEnd=curr;
            else
            {
                oddEnd->next=curr;
                oddEnd=oddEnd->next;
            }
        }
        else
        {
            if(evenHead==nullptr)
                evenHead=evenEnd=curr;
            else
            {
                evenEnd->next=curr;
                evenEnd=evenEnd->next;
            }
        }
        curr=curr->next;
    }
    if(oddHead==nullptr || evenHead==nullptr)
        return head;

    evenEnd->next=oddHead;
    oddEnd->next=nullptr;
    
    return evenHead;
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

    ListNode *head = segregateEvenOdd(dummy->next);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}