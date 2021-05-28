class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int ,int>mp;
        vector<int> fre;
        int ans=0;
        
        int s=0;
        int sum=0;
        int e=0;
        while(e<nums.size())
        {
            if(mp.find(nums[e])==mp.end())
            {
                mp[nums[e]]++;
                sum+=nums[e];
                e++;
            }
            else
            {
                mp.erase(nums[s]);
                sum-=nums[s];
                s++;
            }
            
            if(ans<sum)
            {
                ans=sum;
            }
            
        }
        
        
        return ans;
    }
};