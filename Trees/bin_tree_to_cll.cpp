
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
};

void concat(Node* hl, Node* tl, Node* hr, Node* tr, Node* &head, Node* &tail)
{
    if(hl==nullptr)
    {
        head=hr;
        tail=tr;
        return;
    }
    if(hr==nullptr)
    {
        head=hl;
        tail=tl;
        return;
    }
    tl->right = hr;
    hr->left = tl;
    head=hl;
    tail=tr;
    return;
}
void tree_to_cll(Node* root, Node* &head, Node* &tail)
{
    if(root==nullptr)
        return;
    
    Node* headLeft=nullptr;
    Node* headRight=nullptr;
    Node* tailLeft=nullptr;
    Node* tailRight=nullptr;

    tree_to_cll(root->left, headLeft, tailLeft);
    tree_to_cll(root->right, headRight, tailRight);

    concat(headLeft, tailLeft, root, root, head, tail);
    concat(head, tail, headRight, tailRight, head, tail);


    // cout<<"here";
}


// Display Circular Link List
void displayCList(Node *head)
{
    cout << "Circular Linked List is :\n";
    Node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout << "\n";
}
  
  
// Create a new Node and return its address
Node *newNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
  
// Driver Program to test above function
int main()
{
    Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);
    Node *head = nullptr;
    Node* tail = nullptr;
    tree_to_cll(root, head, tail);
    head->left=tail;
    tail->right=head;

    displayCList(head);
  
    return 0;
}