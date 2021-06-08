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
    int gbv=0;
    TreeNode* find(int s,int e,vector<int>pre,vector<int>ino)
    {
        
        if(s>e)
        {
            return NULL;
        }
        gbv++;
        TreeNode *temp;
        temp=new TreeNode(pre[gbv]);
        //cout<<gbv<<bb;
        int itr;
        for(int i=s;i<=e;i++)
        {
            if(ino[i]==pre[gbv])
            {
                itr=i;
                break;
            }
        }
        temp->left=find(s,itr-1,pre,ino);
        temp->right=find(itr+1,e,pre,ino);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& ino) {
        
        TreeNode *root;
        root=new TreeNode(pre[gbv]);
        //cout<<root->val<<bb;
        int itr;
        for(int i=0;i<ino.size();i++)
        {
            if(ino[i]==pre[0])
            {
                itr=i;
                break;
            }
        }
        
        root->left=find(0,itr-1,pre,ino);
        // cout<<root->left->val<<bb;
        root->right=find(itr+1,ino.size()-1,pre,ino);
        
        return root;
    }
};