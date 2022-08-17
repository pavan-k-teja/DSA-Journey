#include <bits/stdc++.h>
using namespace std;


class DLL
{
public:
    char val;
    DLL *prev;
    DLL *next;

    DLL(char c) : val(c), prev(nullptr), next(nullptr) {}
};

class Solution {

public:
    DLL *node_ptr[26];
    bool repeated_arr[26];
    DLL *head = nullptr;
    DLL *tail = nullptr;

    DLL* addLastDLL(char c)
    {
        DLL* node = new DLL(c);
        if(head == nullptr)
        {
            head = node;
            tail = node;
        }
        else 
        {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }

        return node;
    }

    void deleteDLL(DLL* node)
    {
        if(head == node)
        {
            head = head->next;
            node->next = nullptr;
            delete node;

            if(head == nullptr)
                tail = nullptr;
            
            return;
        }
        
        if(node == tail)
        {
            tail = tail->prev;
            node->prev = nullptr;
            tail->next = nullptr;
            delete node;

            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = node->prev = nullptr;

        delete node;
        return;
    }

    DLL* first_non_rep(char nxtChar)
    {
        int idx = nxtChar - 'a';
        if(repeated_arr[idx] == true)
            return head;

        else if (node_ptr[idx]!= nullptr)
        {
            deleteDLL(node_ptr[idx]);
            repeated_arr[idx] = true;
        }

        else
        {
            DLL* node = addLastDLL(nxtChar);
            node_ptr[idx] = node;
        }
        
        return head;
    }

    Solution() {
        for (int i = 0; i < 26; i++)
        {
            node_ptr[i] = nullptr;
            repeated_arr[i] = false;
        }
    }
};

void printDLL(DLL* head)
{
    cout<<"# ";
    while(head!=nullptr)
    {
        cout<< head->val <<" ";
        head = head->next;
    }
    cout<<"#\n";
}

int main()
{
    char c;
    Solution* sol = new Solution();
    while (true)
    {
        cin >> c;
        char ans;
        DLL* node = sol->first_non_rep(c);
        if(node == nullptr)
            ans = '-';
        else
            ans = node->val;

        cout << "First Non-Repeating Character till now: " << ans << "\n";
        // cout<< sol->head->val<<"...hi\n";

        cout<<"Printing DLL: ";
        printDLL(sol->head);
    }

    return 0;
}