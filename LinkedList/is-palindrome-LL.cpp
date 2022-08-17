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

void reverse(ListNode *&head)
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

bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    //get mid
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *prev = slow;

    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    ListNode *mid = nullptr;

    //divide
    if (fast != nullptr)
    {
        mid = slow;
        slow = slow->next;
        mid->next = nullptr;
    }
    prev->next = nullptr;

    //reverse second half
    reverse(slow);

        // Checking if the second half is reversed
        // ListNode* s=slow;
        // while (s != nullptr)
        // {
        //     cout << s->val << " ";
        //     s = s->next;
        // }

    //check if palin
    bool isPal = true;

    ListNode *iter1 = head;
    ListNode *iter2 = slow;

    while (iter1 != nullptr && iter2 != nullptr)
    {
        if (iter1->val != iter2->val)
        {
            isPal = false;
            break;
        }
        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    // below line is not necessary as both halves have same length
    // if (iter1 != nullptr || iter2 != nullptr)
    //     isPal = false;

    //reverse second half

    reverse(slow);
    
    //join
    if (mid != nullptr)
    {
        prev->next = mid;
        prev = mid;
    }
    prev->next = slow;

    return isPal;
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
    // isPalindrome(dummy->next);

    cout << (boolalpha) << isPalindrome(dummy->next) << endl;

    return 0;
}