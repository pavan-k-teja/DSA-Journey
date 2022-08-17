#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

void width_helper(TreeNode* root, int lvl, int &min_lvl, int &max_lvl)
{
    if(root == nullptr)
        return;
    
    width_helper(root->left, lvl-1, min_lvl, max_lvl);
    
    min_lvl = min(lvl, min_lvl);
    max_lvl = max(lvl, max_lvl);
    
    width_helper(root->right, lvl+1, min_lvl, max_lvl);
    
    
}
int width(TreeNode *root)
{
    int min_lvl = 0;
    int max_lvl = 0;
    width_helper(root, 0, min_lvl, max_lvl);
    return abs(min_lvl) + max_lvl + 1;
}

// input_section=================================================

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    cout << width(root) << endl;
}

int main()
{
    solve();
    return 0;
}