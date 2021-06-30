class Solution {
public:
    #define bb "\n"
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0,e=0;
        
        int zc=0;
        int ans=0;
        while(e<n)
        {
            if(nums[e]==1)
            {
                e++;
            }
            else
            {
                if(zc<k)
                {
                    zc++;
                    e++;
                }
                else
                {
                    while(zc==k)
                    {
                        if(nums[s]==0)
                        {
                            zc--;
                        }
                        s++;
                    }
                }
            }
            ans=max(ans,e-s);
        }
        
        return ans;
    }
};