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
    vector<int>v;
public:
    
    void findBT(TreeNode*root,int h)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(h==1)
        {
            v.push_back(root->val);
        }
        findBT(root->left,h-1);
        findBT(root->right,h-1);
        
        return;
    }
    
    int height(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left=height(root->left)+1;
        int right=height(root->right)+1;
        
        return max(left,right);
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        int h=height(root);
        for(int i=h;i>0;i--)
        {
            findBT(root,i);
            
            if(!v.empty()) ans.push_back(v);
            
            v.clear();
        }
        
        return ans;
    }
};