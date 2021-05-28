/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int findS(TreeNode*root,int p,int g)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int Ip=root->val%2==0?1:0;
        int Ig=p;
        int sum=0;
        if(g)
        {
            sum=root->val;
        }
        int ls=sum+findS(root->left,Ip,Ig);
        int rs=findS(root->right,Ip,Ig);
        
        return ls+rs;
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        int ans=findS(root,0,0);
        return ans;
    }
};