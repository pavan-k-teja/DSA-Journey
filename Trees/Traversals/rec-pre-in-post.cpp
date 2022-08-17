
void preOrder(TreeNode* root)
{
    if(root == nullptr)
        return root;
    
    ans.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(TreeNode* root)
{
    if(root == nullptr)
        return root;
    
    inOrder(root->left);
    ans.push_back(root->val);
    inOrder(root->right);
}


void postOrder(TreeNode* root)
{
    if(root == nullptr)
        return root;
    
    postOrder(root->left);
    postOrder(root->right);
    ans.push_back(root->val);
}