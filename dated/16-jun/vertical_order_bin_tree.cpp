#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
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

//O(N) TC and SC
vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    vector<vector<int>>v;
    if(root == nullptr)
        return {};
        
    // pair<Node*, int>
    unordered_map<int, vector<int>> umap;
    
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    // umap[0].push_back(root->val);
    int min_lvl = 0;
    int max_lvl = 0;
    while(!q.empty())
    {
        pair<TreeNode*, int> curr = q.front();
        q.pop();
        umap[curr.second].push_back((curr.first)->val);
        
        min_lvl = min(min_lvl, curr.second);
        max_lvl = max(max_lvl, curr.second);
        
        if((curr.first)->left !=nullptr)
            q.push(make_pair((curr.first)->left, curr.second -1));
        
        if((curr.first)->right !=nullptr)
            q.push(make_pair((curr.first)->right, curr.second + 1));
            
    }
    for(int i=min_lvl; i<=max_lvl; i++)
        v.push_back(umap[i]);
        
    return v;
    
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

    vector<vector<int>> ans = verticalOrderTraversal(root);
    int idx = 0;
    for (vector<int> &i : ans)
    {
        cout << idx++ << " -> ";
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    solve();
    return 0;
}



int main()
{
    



    return 0;
}