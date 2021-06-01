class Solution {
public:
    
    int findArea(vector<vector<int>> &v,int i,int j,int m, int n)
    {
        if(i<0 || j<0)
        {
            return 0;
        }
        if(i>=m || j>=n)
        {
            return 0;
        }
        
        if(v[i][j]==0)
        {
            return 0;
        }
        
        
        v[i][j]=0;
        
        int left=findArea(v,i,j-1,m,n)+1;
        int right=findArea(v,i,j+1,m,n);
        int up=findArea(v,i-1,j,m,n);
        int down=findArea(v,i+1,j,m,n);
        
        //v[i][j]=1;
        
        return left+right+down+up;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int islandArea=0;
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    islandArea=findArea(grid,i,j,row,col);
                    //cout<<islandArea<<endl;
                    ans=max(ans,islandArea);
                    islandArea=0;
                }
            }                
        }
        return ans;
        
    }
};