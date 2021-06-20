class Solution {
public:
    
    #define bb "\n"
    
    class Tile{
        public:
        int x;
        int y;
        int tE;
        Tile(int x,int y,int tE)
        {
            this->x=x;
            this->y=y;
            this->tE=tE;
        }
    };
    
    class CTime{
        public:
        bool operator()(Tile const& a,Tile const& b)
        {
            return a.tE > b.tE;
        }
    };
        
    
    int swimInWater(vector<vector<int>>& grid) {
        
        vector<vector<int>>steps={{0,-1},{-1,0},{0,1},{1,0}};
        
        int n=grid.size();
        bool vis[51][51]={false};
        
        priority_queue<Tile,vector<Tile>,CTime>pq;
        
        
        int leastTime=grid[0][0];
        vis[0][0]=true;
        
        pq.push(Tile(0,0,grid[0][0]));
        
        while(!pq.empty())
        {
            Tile curr=pq.top();
            //cout<<curr.x<<" "<<curr.y<<bb;
            pq.pop();
            
            leastTime=max(curr.tE,leastTime);
            
            if(curr.x==n-1 && curr.y==n-1)
            {
                break;
            }
            
            //cout<<"//// ///// ////"<<bb;
            
            for(auto stp:steps)
            {
                int nextX=curr.x+stp[0];
                int nextY=curr.y+stp[1];
                
                //cout<<nextX<<"  "<<nextY<<bb;
                
                if(nextX<0 || nextX==n || nextY<0 || nextY==n)
                {
                    continue;
                }
                if(vis[nextX][nextY])
                {
                    continue;
                }
                
                vis[nextX][nextY]=true;
                pq.push(Tile(nextX,nextY,grid[nextX][nextY]));
                
            }
            
           //cout<<"//// ///// ////"<<bb;
            
        }
        
        return leastTime;
    }
};