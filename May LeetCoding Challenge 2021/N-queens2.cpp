class Solution {
int ans=0;
public:
    
    bool check(int n,int arr[][10],int r,int c)
    {
        for(int i=0;i<r;i++)
        {
            if(arr[i][c]==1)
                return false;
        }
        
        int x=r,y=c;
        while(x>=0 && y>=0)
        {
            if(arr[x][y]==1)
                return false;
            x--;
            y--;
        }
        x=r;
        y=c;
        
        while(x>=0 && y<n)
        {
            if(arr[x][y]==1)
                return false;
            x--;
            y++;
        }
        
        return true;
    }
    
    void find(int n,int arr[][10],int i)
    {
        if(i==n)
        {
            ans++;
            return;
        }
        
        for(int j=0;j<n;j++)
        {
            if(check(n,arr,i,j))
            {
                arr[i][j]=1;
                find(n,arr,i+1);
                arr[i][j]=0;
            }
        }
    }
    
    int totalNQueens(int n) {
        int arr[10][10]={0};
        find(n,arr,0);
        return ans;
    }
};