class Solution {
public:
    
    #define bb "\n"
    
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        
        vector<vector<int>>ans;
        priority_queue<pair<int,int>>pq;
        
        int dis;
        for(int i=0;i<p.size();i++)
        {
            dis=p[i][0]*p[i][0] + p[i][1]*p[i][1];
            //cout<<dis<<bb;
            pq.push(make_pair(-dis,i));
        }
        while(k--)
        {
            pair<int,int>itr=pq.top();
            ans.push_back(p[itr.second]);
            pq.pop();
        }
        return ans;
    }
};