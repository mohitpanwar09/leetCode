class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        
        int hmax=-1;
        int vmax=-1;
        long long int modul=1000000007;
        long long int ans;
        
        for(int i=0;i<=hc.size();i++)
        {   
            if(i==0)
            {
                hmax=max(hmax,abs(0-hc[i]));
                continue;
            }
            if(i==hc.size())
            {
                hmax=max(hmax,abs(hc[i-1]-h));
                continue;
            }
            
            hmax=max(hmax,abs(hc[i-1]-hc[i]));
        }
        
        for(int i=0;i<=vc.size();i++)
        {   
            if(i==0)
            {
                vmax=max(vmax,abs(0-vc[i]));
                continue;
            }
            if(i==vc.size())
            {
                vmax=max(vmax,abs(vc[i-1]-w));
                continue;
            }
            
            vmax=max(vmax,abs(vc[i-1]-vc[i]));
        }
        
        ans=(hmax%modul*vmax%modul)%modul ;
        //cout<<ans<<endl;
        // ans%=modul;
        return ans;
        
    }
};