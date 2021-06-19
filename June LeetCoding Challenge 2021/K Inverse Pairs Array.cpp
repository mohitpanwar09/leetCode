class Solution {
public:
    
    #define mod 1000000007
    int kInversePairs(int n, int k) {
        int arr[1001][1001]={0};
        // for(int i=0;i<=n/2;i++)
        // {
        //     for(int j=0;j<=k/2;j++)
        //         arr[i][j]=0;
        // }
         for(int i=1;i<=n;i++)
         {
             for(int j=0;j<=k;j++)
             {
                 if(j==0)
                 {
                     arr[i][j]=1;
                 }
                 else
                 {
                     for(int l=0;l<=min(j,i-1);l++)
                     {
                         arr[i][j]=(arr[i][j]+arr[i-1][j-l])%1000000007;
                     }
                 }
             }
         }
       return arr[n][k]; 
    }
};