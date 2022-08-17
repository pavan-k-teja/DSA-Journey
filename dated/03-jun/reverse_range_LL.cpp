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

// temporary head, temporary tail


void addFirstNode(ListNode *node, ListNode *&tempHead, ListNode *&tempEnd)
{
    if (tempHead == nullptr)
    {
        tempHead = node;
        tempEnd = node;
    }
    else
    {
        node->next = tempHead;
        tempHead = node;
    }
}

ListNode *reverseInRange(ListNode *head, int m, int n)
{
    //TC=O(n) and only 1 pass, SC=O(1)
    if (head == nullptr || head->next == nullptr || m == n)
        return head;

    ListNode* curr= head;
    ListNode* prev= nullptr;
    int count=1;
    while(curr!=nullptr && count<m)
    {
        prev=curr;
        curr=curr->next;
        count++;
    }
    if(curr==nullptr)
        return head;

    ListNode *tempHead = nullptr;
    ListNode *tempEnd = nullptr;
    
    while(curr!=nullptr && count<=n)
    {
        ListNode* temp=curr;
        curr=curr->next;
        count++;
        temp->next=nullptr;

        addFirstNode(temp, tempHead, tempEnd);
    }
    if(prev!=nullptr)
        prev->next = tempHead;
    else
        head=tempHead;
    tempEnd->next=curr;

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
    int len;
    cin >> len;
    ListNode *h1 = createList(len);
    int m, n;
    cin >> m >> n;
    h1 = reverseInRange(h1, m, n);
    printList(h1);

    return 0;
}