

void postorder(Node *root)
{
    Node *curr = root;
    stack<Node *> st;
    while (true)
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top()->right;
            if (curr == nullptr)
            {
                Node *last = nullptr;
                while (!st.empty() && st.top()->right == last)
                {
                    last = st.top();
                    st.pop();
                    cout << last->value << '\n';
                }
            }
        }
    }
}
