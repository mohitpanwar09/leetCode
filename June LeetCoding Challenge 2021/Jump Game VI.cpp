class Solution {
public:
    #define bb "\n"
    int maxResult(vector<int>& n, int k) {
        
        priority_queue<pair<int,int>>pq;
        
        int scor=0;
        int ans=0;
       
        pq.push(make_pair(n[0],0));
        

        for(int i=1;i<n.size()-1;i++)
        {
            pair<int,int>itr=pq.top();
            if(!(i - itr.second<=k))
            {
                pq.pop();
                i--;
                continue;
            }
            itr=pq.top();
            scor=itr.first+n[i];
        
            pq.push(make_pair(scor,i));
            
        }
        pair<int,int> itr=pq.top();
        if(!(n.size()-1 - itr.second<=k))
        {
                pq.pop();
        }
        itr=pq.top();
        if(n.size()!=1)
        ans=itr.first+n[n.size()-1];
        else
        ans=itr.first;
        return ans;
    }
};