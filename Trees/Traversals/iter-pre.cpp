vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> preorder;
    if (root == nullptr)
        return preorder;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode* curr = st.top();
        st.pop();

        preorder.push_back(curr->val);

        if (curr->right != nullptr)
            st.push(curr->right);
        if (curr->left != nullptr)
            st.push(curr->left);
    }
    return preorder;
}