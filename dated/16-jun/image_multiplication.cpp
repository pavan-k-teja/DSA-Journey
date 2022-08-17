// https://practice.geeksforgeeks.org/problems/image-multiplication0627/1

class Solution
{
    long long mod = 1e9+7;
    public:
    long long imgMul_helper(Node* root1, Node* root2)
    {
        if(root1 == NULL || root2 == NULL)
            return 0;
        
        long long sum = (long long)root1->data * (long long)root2->data;
        sum %= mod;
        
        if(root1->left!=NULL)
            sum += (imgMul_helper(root1->left, root2->right) % mod);
        sum %= mod;
        if(root1->right!=NULL && root1 != root2)
            sum += (imgMul_helper(root1->right, root2->left) % mod);
        
        return sum % mod;
        
    }
    long long imgMultiply(Node *root)
    {
        return imgMul_helper(root, root);
    }
};
