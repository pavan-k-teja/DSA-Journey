//Leetcode-86

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *lessHead = new ListNode(-1);
        ListNode *greatHead = new ListNode(-1);
        ListNode *lessEnd = lessHead;
        ListNode *greatEnd = greatHead;

        ListNode *curr = head;
        while (curr != nullptr)
        {
            if (curr->val < x)
            {
                lessEnd->next = curr;
                lessEnd = lessEnd->next;
            }
            else
            {
                greatEnd->next = curr;
                greatEnd = greatEnd->next;
            }
            curr = curr->next;
        }

        if (lessHead->next == nullptr || greatHead->next == nullptr)
            return head;
        greatEnd->next=nullptr;
        lessEnd->next = greatHead->next;
        return lessHead->next;
    }
};
