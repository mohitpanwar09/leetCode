class Solution {
public:
    int maximumGap(vector<int>& n) {
        int ans=0;
        
        sort(n.begin(),n.end());
        for(int i=1;i<n.size();i++)
        {
            ans=max(ans,n[i]-n[i-1]);
        }
        return ans;
    }
};