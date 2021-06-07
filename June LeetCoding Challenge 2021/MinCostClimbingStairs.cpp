class Solution {
public:
    #define bb "\n"
    
    int ans=INT_MAX;
    int sum=0;
    int mp[1001];
    int find(vector<int> c, int i)
    {
        // base case
        if(i>=c.size())
        {
            ans=min(ans,sum);
            return 0;
        }
        

        if(mp[i]!=-1)
        {
            //cout<<mp[i]<<bb;
                ans=sum+min(ans,mp[i]);
                return mp[i];
        }
    
        sum+=c[i];
        int left=find(c,i+1);
        int right=find(c,i+2);
        sum-=c[i];
        mp[i]=(c[i]+min(left,right));
        //cout<<mp[i]<<bb;
        return mp[i];
    }
    
    int minCostClimbingStairs(vector<int>& c) {
        
        for(int i=0;i<c.size();i++)
        {
            mp[i]=-1;
        }
        int minNo1=find(c,0);
        sum=0;
        int minNo2=find(c,1);
        return ans;
    }
};