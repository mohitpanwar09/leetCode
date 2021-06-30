/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int,int>mp;
    bool On=false;
    TreeNode*ans;
    TreeNode* find(TreeNode* root,TreeNode* key)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==key->val)
        {
            if(mp.find(root->val)!=mp.end() && !On)
            {
                ans=root;
                On=true;
            }
            else
            {
                mp[root->val]++;
            }
            return root;
        }
        
        TreeNode* left=find(root->left,key);
        
        if(left==NULL)
        {
            TreeNode* right=find(root->right,key); 
            
            if(right==NULL)
            {
                return NULL;
            }
            
            if(mp.find(root->val)!=mp.end() && !On)
            {
                ans=root;
                On=true;
            }
            else
            {
                mp[root->val]++;
            }
            
            return right;
                
        }
        else
        {
            if(mp.find(root->val)!=mp.end() && !On)
            {
                ans=root;
                On=true;
            }
            else
            {
                mp[root->val]++;
            }
        }
        
        return left;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
        TreeNode* key1=find(root,p);
        TreeNode* key2=find(root,q);
        
        return ans;
    }
};