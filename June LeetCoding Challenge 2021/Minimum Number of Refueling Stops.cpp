class Solution {
public:
    int minRefuelStops(int target, int sf, vector<vector<int>>& st) {
        //keep reaching the farthmost station while filling most gas
        int n=st.size();
        priority_queue<int>pq;
        int ans=0;
        bool add=false;
        if(n==0)
        {
            if(target<=sf)
                return 0;
            else
                return -1;
        }
        for(int i=0;i<n;i++)
        {
            add=false;
            if(i==0){
                sf-=st[i][0];
            }else{    
                sf-=st[i][0]-st[i-1][0];
            }
            if(sf==0)
            {
               pq.push(st[i][1]);
                add=true;
            }
            if(sf<=0)
            {
                if(!pq.empty())
                {
                    while(sf<=0){
                        if(!pq.empty()){
                            sf+=pq.top();
                            pq.pop();
                            ans++;
                        }
                        else
                            return -1;
                    }
                }
                else
                {
                    return -1;
                }
            }
            if(!add)
                pq.push(st[i][1]);
            
        }
        if(target-st[n-1][0]<=sf)
            return ans;
        else
        {
            if(!pq.empty())
                {
                    while(sf<target-st[n-1][0]){
                        if(!pq.empty()){
                            sf+=pq.top();
                            pq.pop();
                            ans++;
                        }
                        else
                            return -1;
                    }
                }
            return ans;
        }
        
    }
};