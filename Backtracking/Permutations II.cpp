class Solution {
    vector<int>v;
    map<int,int>mp;
    vector<vector<int>>ans;
        
public:
    
    void findP(vector<int>& n)
    {
        if(v.size()==n.size())
        {
            
            ans.push_back(v);
            
            return ;
        }
        
        for(auto i:mp)
        {
            
            if(i.second>0)
            {
                mp[i.first]--;
                v.push_back(i.first);
                findP(n);
            
                if(!v.empty())
                {   
                    v.pop_back();
                }
                mp[i.first]++;
            }    
         
            
        }
       
        return ;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        findP(nums);
        v.clear();
        return ans;
    }
};