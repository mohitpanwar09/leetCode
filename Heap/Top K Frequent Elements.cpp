class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        map<int,int>mp;
        map<char,int>mp
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto itr:mp)
        {
            pq.push(make_pair(itr.second,itr.first));
        }
        
        while(k--)
        {
            pair<int,int> itr=pq.top();
            ans.push_back(itr.second);
            pq.pop();
        }
        
        return ans;
    }
};