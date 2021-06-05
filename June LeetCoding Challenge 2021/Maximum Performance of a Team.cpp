class Solution {
public:
    #define ll long long int
    #define bb "\n"
    #define mod 1000000007
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        
        vector<pair<int,int>> set;
        ll ans=0;
        ll sum=0;
        
        for(int i=0;i<n;i++)
        {
            set.push_back(make_pair(ef[i],sp[i]));
        }
        sort(set.rbegin(),set.rend());
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<set[i].first<<" "<<set[i].second<<bb;
        // }
        
        priority_queue<int> speed;
        
        for(int i=0;i<n;i++)
        {
           ll minef=set[i].first;
           sum+=set[i].second;
           //cout<<sum<<bb;
            ans=max(ans,sum*minef);
            //cout<<ans<<bb;
           speed.push(-1*set[i].second);
           
           if(speed.size()>k-1)
           {
               sum-=(-1*speed.top());
               speed.pop();
           }
              
        }
        return  ans%mod;
        
    }
};