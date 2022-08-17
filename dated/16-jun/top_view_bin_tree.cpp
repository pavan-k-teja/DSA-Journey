#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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


void width(TreeNode* root, int curr_lvl, int &min_lvl, int &max_lvl)
{
    if(root == nullptr)
        return;
    
    min_lvl = min(curr_lvl, min_lvl);
    max_lvl = max(curr_lvl, max_lvl);

    width(root->left, curr_lvl-1, min_lvl, max_lvl);
    width(root->right, curr_lvl+1, min_lvl, max_lvl);
}

//O(N) TC and SC. Same complexity but we use array here
vector<int> TopView(TreeNode *root)
{
    if(root == nullptr)
        return {};

    int min_lvl = 0;
    int max_lvl = 0;
    width(root, 0, min_lvl, max_lvl);

    int wdth = max_lvl - min_lvl + 1;
    int root_idx = -min_lvl;

    vector<int> arr(wdth, INT_MIN);
        
    // pair<Node*, int>
    
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, root_idx));
    
    while(!q.empty())
    {
        pair<TreeNode*, int> curr = q.front();
        q.pop();
        if(arr[curr.second] == INT_MIN)
            arr[curr.second] = (curr.first)->val;
        
        if((curr.first)->left !=nullptr)
            q.push(make_pair((curr.first)->left, curr.second -1));
        
        if((curr.first)->right !=nullptr)
            q.push(make_pair((curr.first)->right, curr.second + 1));
            
    }
    
        
    return arr;
    
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

    vector<int> ans = TopView(root);

    for (int i : ans)
    {
        cout << i << " ";
    }
}

int main()
{
    solve();
    return 0;
}