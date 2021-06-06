class Solution {
public:
    #define bb "\n"
    
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int l=1;
        int ans=0;
        map<int,int>mp;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto i:mp)
        {
            v.push_back(i.first);
        }
        
        for(int i=0;i<v.size();i++)
        {
            if(i==0)
            {
                l=1;
                ans=max(ans,l);
                continue;
            }
        
            if(v[i]-v[i-1]==1)
            {
                l++;
                ans=max(ans,l);
                continue;
            }
            
            l=1;
            ans=max(ans,l);
        }
        
        return ans;
        
    }
};