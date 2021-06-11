class Solution {
public:
    #define bb "\n"
    
    
    int stoneGameVII(vector<int>& st) {
        
       int n=st.size();
        int dp[1001]={0};
        for(int i=n-1;i>=0;i--)
        {
            int temp=0;
            int sum=st[i];
            for(int j=i;j<n;j++)
            {
                if(i!=j)
                {
                    sum+=st[j];
                    int a=sum-st[j];
                    int b=sum-st[i];
                    dp[j]=max(a-temp,b-dp[j]);
                }
                temp=dp[j];
            }
        }
        return dp[n-1];
    }
};