class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans;
        int maxN=1<<maximumBit;
        maxN--;
        int ttX=0;
        for(int i=0;i<nums.size();i++)
        {
            ttX^=nums[i];
        }
        ans.push_back(ttX^maxN);
        
        for(int i=nums.size()-1;i>0;i--)
        {
            ttX^=nums[i];
            ans.push_back(ttX^maxN);
        }
        
        return ans;
    }
};