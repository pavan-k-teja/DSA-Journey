#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    int val;
};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postorder;
    if (root == nullptr)
        return postorder;
        
    stack<TreeNode *> st1, st2;
    st1.push(root);

    while (!st1.empty())
    {
        TreeNode* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left != nullptr)
            st1.push(curr->left);
        if (curr->right != nullptr)
            st1.push(curr->right);
    }
    while (!st2.empty())
    {
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
}