class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& ns, int left, int right) {
        int n=ns.size();
        int ans=0;
        int wd=0;
        int i=0,j=0;
        while(i<n && j<n)
        {
            if(ns[j]<left)
            {
                ans+=wd;
                j++;
                continue;
            }
            
            if(ns[j]>=left && ns[j]<=right)
            {
                wd=j-i+1;
                ans+=wd;
                j++;
                continue;
            }
            
            if(ns[j]>right)
            {
                wd=0;
                i=j+1;
                j++;
            }
            
        }
        
        return ans;
    }
};