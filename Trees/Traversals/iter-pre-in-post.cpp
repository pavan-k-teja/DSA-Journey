#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    TreeNode* left;
    TreeNode* right;
    int val;
};

vector<vector<int>> allOrderTraversal(TreeNode *root)
{
    /*
        1 - pre, s++, left
        2 - in, s++, right
        3 - post, pop
    */
    vector<vector<int>> ans;
    vector<int> pre, in, post;

    if (root == nullptr)
        return ans;
    
    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto it = st.top();

        if (it.second == 1)
        {
            pre.push_back(it.first->val);
            it.second++;

            if (it.first->left != nullptr)
                st.push({it.first->left, 1});
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->val);
            it.second++;

            if (it.first->right != nullptr)
                st.push({it.first->right, 1});
        }
        else
        {
            post.push_back(it.first->val);
            st.pop();
        }
    }

    
    ans.pb(pre);
    ans.pb(in);
    ans.pb(post);
    return post;
}