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
    #define bb "\n"
    
    queue<int> level;
    
    void find(TreeNode*root,int l)
    {
        if(root==NULL)
        {
          return;  
        }
        
        if(l==1)
        {
            level.push(root->val);
            return;
        }
        
        find(root->left,l-1);
        find(root->right,l-1);
        
        return;
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        int size;
        for(int i=1;;i++)
        {
            size=level.size();
            find(root,i);
            if(size==level.size())
                break;
            
            ans.push_back(level.back());
            
        }
        return ans;
    }
};