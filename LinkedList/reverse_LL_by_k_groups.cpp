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

int length_LL(ListNode *head)
{
    int len = 0;
    while (head != nullptr)
    {
        len++;
        head = head->next;
    }
    return len;
}

void addFirstNode(ListNode *node, ListNode* &tempHead, ListNode* &tempTail)
{
    if(tempHead == nullptr)
    {
        tempHead = node;
        tempTail = node;
    }
    else
    {
        node->next = tempHead;
        tempHead = node;
    }
}
ListNode *reverseInKGroup(ListNode *head, int k)
{
    //TC=O(n), SC=O(1)
    if (head == nullptr || head->next == nullptr || k <= 1)
        return head; // edge cases

    int len = length_LL(head);

    //seperate k grouped ll, then reverse it, then attach it to result LL.

    ListNode* tempHead = nullptr;
    ListNode* tempTail = nullptr;

    ListNode* resultHead = new ListNode(-1);
    ListNode* resultTail = resultHead;

    ListNode* curr = head;

    while(curr!=nullptr && len>=k)
    {
        int count = 0;
        while(count < k)
        {
            ListNode* temp = curr;
            curr = curr->next;
            temp->next = nullptr;
            addFirstNode(temp, tempHead, tempTail);
            count++;
        }

        resultTail->next = tempHead;
        resultTail = tempTail;

        tempHead = tempTail = nullptr;
        len-=k;
    }
    resultTail->next = curr;
    
    return resultHead->next; 
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
    int k;
    cin >> k;
    h1 = reverseInKGroup(h1, k);
    printList(h1);

    return 0;
}