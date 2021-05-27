class Solution {
    vector<int>v;
    vector<vector<int>>ans;
        
public:
    
    bool check(vector<int>&v ,int no)
    {
        for(int i=0;i<v.size();i++)
        {
            // cout<<v[i]<<" "<<no<<endl;
            if(v[i]==no)
                return false;
        }
        return true;
    }
    
    void findP(vector<int>& n,int s)
    {
        if(s==n.size()-1)
        {
            for(int k=0;k<n.size();k++)
            {
                if(check(v,n[k]))
                {
                    //cout<<n[k]<<" ";
                    v.push_back(n[k]);
                    break;
                }
                
            }
        
            
            ans.push_back(v);
            v.pop_back();
            
            return ;
        }
        
        for(int i=0;i<n.size();i++)
        {
            
            if(check(v,n[i]))
            {
               v.push_back(n[i]);
               findP(n,s+1);
            
                if(!v.empty())
                v.pop_back();
            }    
         
            
        }
       
        return ;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        findP(nums,0);
        v.clear();
        return ans;
    }
};