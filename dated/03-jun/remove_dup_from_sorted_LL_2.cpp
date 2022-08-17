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

        ListNode* dummy = new ListNode(-1);
        ListNode* prev=dummy;
        dummy->next=head;
        ListNode* curr=head;

        while(curr!=nullptr)
        {
            while(curr->next!=nullptr && curr->val == curr->next->val)
                curr=curr->next;
            
            if(prev->next!=curr)
                prev->next=curr->next;
            else
                prev=prev->next;
                
            curr=curr->next;
        }
        return dummy->next;
    }
};