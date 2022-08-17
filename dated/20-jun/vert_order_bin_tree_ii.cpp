#include <iostream>
#include <vector>
#include <queue>
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

struct comp
{
    bool operator()(const pair<TreeNode*, int>lhs, const pair<TreeNode*, int>rhs) 
    const {
        //default order of priority queue is max heap
        return (lhs.first)->val > (rhs.first)->val;
    }
};

vector<vector<int>> verticalOrderTraversal(TreeNode *root)
{
    vector<vector<int>>ans;
    if(root == nullptr)
        return {};

    int min_lvl = 0;
    int max_lvl = 0;
    width(root, 0, min_lvl, max_lvl);

    int wdth = max_lvl - min_lvl + 1;
    int root_idx = -1*min_lvl;

    vector<int> arr[wdth];
        
    // pair<Node*, int>
    
    priority_queue<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>, comp> pq_parent;
    priority_queue<pair<TreeNode*, int>, vector<pair<TreeNode*, int>>, comp> pq_child;

    pq_parent.push(make_pair(root, root_idx));
    
    while(!pq_parent.empty())
    {
        int pq_size = pq_parent.size();
        while(pq_size > 0)
        { 
            pair<TreeNode*, int> curr = pq_parent.top();
            pq_parent.pop();
            arr[curr.second].push_back((curr.first)->val);
            
            if((curr.first)->left !=nullptr)
                pq_child.push(make_pair((curr.first)->left, curr.second -1));
            
            if((curr.first)->right !=nullptr)
                pq_child.push(make_pair((curr.first)->right, curr.second + 1));
        
            pq_size--;
        }    
        pq_parent.swap(pq_child);
    }
    for(int i=0; i< wdth; i++)
        ans.push_back(arr[i]);
        
    return ans;
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