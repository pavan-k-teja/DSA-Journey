#include <iostream>
#include <vector>
#include <queue>

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

//******************************************
//TC=O(2n)
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;

    if (l2 == nullptr)
        return l1;

    ListNode *dummy = new ListNode(-1);
    ListNode *result = dummy;
    ListNode *last = dummy;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            last->next = l1;
            last = l1;
            l1 = l1->next;
        }
        else
        {
            last->next = l2;
            last = l2;
            l2 = l2->next;
        }
    }
    if (l1 != nullptr)
        last->next = l1;
    if (l2 != nullptr)
        last->next = l2;

    result = result->next;
    dummy->next = nullptr;
    delete dummy;

    return result;
}

//TC=O(nk logk) SC=O(log k)
ListNode *mergeKLists(vector<ListNode *> &lists, int si, int ei)
{
    if (si > ei)
        return nullptr;
    if (si == ei)
        return lists[si];
    int mid = (ei - si) / 2 + si;
    ListNode *l1 = mergeKLists(lists, si, mid);
    ListNode *l2 = mergeKLists(lists, mid + 1, ei);

    return mergeTwoLists(l1, l2);
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    return mergeKLists(lists, 0, lists.size() - 1);
}


//*****************************************
struct comp
{
    bool operator()(const ListNode *lhs, const ListNode *rhs) const {
        return lhs->val > rhs->val;
    }
};
//TC=O(nk logk) SC=O(k)
ListNode *mergeKLists_2(vector<ListNode *> &lists)
{

    priority_queue<ListNode *, vector<ListNode *>, comp> pq;
    //default order of priority queue is max heap
    
    for(int i=0;i<lists.size();i++)
        if(lists[i]!=nullptr)
            pq.push(lists[i]);

    ListNode* dummy=new ListNode(-1);
    ListNode* result= dummy;
    ListNode* last= dummy;

    while(!pq.empty())
    {
        last->next=pq.top();
        pq.pop();
        last=last->next;
        if(last->next!=nullptr)
            pq.push(last->next);
    }

    result=result->next;
    delete dummy;

    return result;
}
//****************************************

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
    vector<ListNode *> list(n, 0);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        list[i] = createList(m);
    }

    ListNode *head = mergeKLists_2(list);
    printList(head);

    return 0;
}