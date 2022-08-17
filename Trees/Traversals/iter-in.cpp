vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    if (root == nullptr)
        return inorder;

    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != nullptr || !st.empty())
    {
        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        inorder.push_back(curr->val);
        curr = curr->right;
    }
    return inorder;
}