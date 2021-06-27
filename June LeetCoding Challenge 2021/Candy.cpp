class Solution {
public:
    #define bb "\n"
    int candy(vector<int>& rs) {
        int n=rs.size();
        int ans=0;
        //cout<<n<<bb;
        vector<int>cd(n,1);
        if(n==1)
        {
            return 1;
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(rs[i]>rs[i+1])
                {
                    cd[i]+=abs(cd[i]-cd[i+1])+1;
                }
                continue;
            }
            
            if(i==n-1)
            {
                if(rs[i]>rs[i-1])
                {
                    cd[i]+=abs(cd[i]-cd[i-1])+1;
                }
                continue;
            }
            
            if(rs[i]>rs[i-1])
            {
                cd[i]+=abs(cd[i]-cd[i-1])+1;
            }
            if(rs[i]>rs[i+1])
            {
                if(cd[i]<=cd[i+1])
                {
                    cd[i]+=abs(cd[i]-cd[i+1])+1;
                }
            }
            
        }
        for(int i=n-1;i>=0;i--)
        {
            if(i==0)
                continue;
            
            if(rs[i]<rs[i-1])
            {
                if(cd[i]>=cd[i-1])
                {
                    cd[i-1]=cd[i]+1;
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            // cout<<cd[i]<<" ";
            ans+=cd[i];
        }
        return ans;
    }
};