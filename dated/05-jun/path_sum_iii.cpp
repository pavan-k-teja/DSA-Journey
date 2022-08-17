//Leetcode-437

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {
    
    int pathSum_with_top(TreeNode* root, int targetSum)
    {
        if(root==nullptr)
            return 0;
        
        int count=0;
        if(root->val==targetSum)
            count++;
        count += pathSum_with_top(root->left, targetSum - root->val);
        count += pathSum_with_top(root->right, targetSum - root->val);
        
        return count;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return 0;
        
        int leftPaths = pathSum(root->left, targetSum);
        int rightPaths = pathSum(root->right, targetSum);
        int paths_including_top = pathSum_with_top(root, targetSum);
        
        return leftPaths + rightPaths + paths_including_top;
        
    }
};