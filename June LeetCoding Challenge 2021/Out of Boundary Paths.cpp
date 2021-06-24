class Solution {
public:
    #define mod 1000000007
    #define ll long long int
    ll v[51][51][51];
    
    int find(int m, int n, int maxM, int i, int j)
    {
        
        if(i<0 || j<0 || i>=m || j>=n)
        {
            //ans=(ans%mod + 1%mod)%mod;
            return 1;
        }
        if(maxM==0)
        {
            return 0;
        }
        
        if(v[i][j][maxM]!=-1)
        {
            return v[i][j][maxM];
        }
        ll path=0;
        
        ll up=find(m,n,maxM-1,i-1,j);
        ll down=find(m,n,maxM-1,i+1,j);
        ll right=find(m,n,maxM-1,i,j+1);
        ll left=find(m,n,maxM-1,i,j-1);
        
        path=( up + down + right + left )%mod ;
        v[i][j][maxM]=path;
        return (int)path;
        
    }
    
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        
        
        //vector<vector<int>> vec( n , vector<int> (m, 0));
        memset(v,-1,sizeof(v));
        int ans=find(m,n,maxMove,startRow,startColumn);
        return ans;
    }
};