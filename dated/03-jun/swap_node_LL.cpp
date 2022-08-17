/** Leetcode-1721
 * Definition for singly-linked list.
 * #include<iostream>
 * #include<algorithm> // for std:swap
 * #include <utility> // for std::pair, std::make_pair
 * 
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, ListNode*> kth_node(ListNode* head, int k)
    {
        ListNode* curr=head;
        int count=1;
        while(curr!=nullptr && count<k)
        {
            curr=curr->next;
            count++;
        }
        if(curr==nullptr)
            return {nullptr, nullptr};
        ListNode* first = curr;
        curr=curr->next;
        ListNode* second=head;
        while(curr!=nullptr)
        {
            curr=curr->next;
            second=second->next;
        }
        
        return {first, second};
        
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)
            return head;
        pair<ListNode*, ListNode*> pos=kth_node(head, k);
        swap(pos.first->val, pos.second->val);
        
        return head;
    }
};