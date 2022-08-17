/**Leetcode-725
 Definition for singly-linked list.*/

 //need to solve this
 #include<vector>
 using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    
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
    
    ListNode* split(ListNode* &curr, int len_now)
    {
        ListNode* dummy= new ListNode(-1);
        ListNode* last=dummy;
        
        int count =0;
        while(count<len_now)
        {
            last->next = curr;
            last = curr;
            if(curr!=nullptr)
                curr = curr->next;
            count++;
        }
        if(last!=nullptr)
            last->next =nullptr;
        return dummy->next;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        vector<ListNode*> ans;
        int len=length_LL(head);
        
        int len_now = (len + k) / k ;
        int big_len_count = len % k;
        int count = 0; 
        
        ListNode* curr=head;

        while(count < big_len_count && count<k)
        {
            ans.push_back(split(curr, len_now));
            count++;
            
        }
        len_now--;
        while(count < k)
        {
            ans.push_back(split(curr, len_now));
            count++;
        }
        return ans;
    }
};