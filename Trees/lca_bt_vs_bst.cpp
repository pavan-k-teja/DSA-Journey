#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};


TreeNode *LCA_BT(TreeNode *root, int p, int q)
{
    // base case
    if (root == nullptr || root->val == p || root->val == q)
        return root;
    
    TreeNode *left = LCA_BT(root->left, p, q);
    TreeNode *right = LCA_BT(root->right, p, q);

    if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    else
        return root;
}

TreeNode *LCA_BST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (!root)
        return nullptr;

    int curr = root->val;

    if (curr < p->val && curr < q->val)
        return LCA_BST(root->right, p, q);

    if (curr > p->val && curr > q->val)
        return LCA_BST(root->left, p, q);

    return root;
}



int main()
{

    

    return 0;
}