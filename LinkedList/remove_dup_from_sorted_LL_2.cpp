/* Leetcode-82
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**/

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *resHead = new ListNode(-1);
        ListNode *resTail = resHead;
        resHead->next = head; // its a possible node
        ListNode *curr = head;

        while (curr != nullptr)
        {
            while (curr->next != nullptr && curr->val == curr->next->val)
                curr = curr->next;

            if (resTail->next != curr)
                resTail->next = curr->next; // its a possible node
            else
                resTail = resTail->next;

            curr = curr->next;
        }
        return resHead->next;
    }
};