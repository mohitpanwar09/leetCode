class Solution {
public:
    
    #define ll long long int
    
    bool find(ll s1,ll s2,ll s3,ll s4,vector<int>v, int i,int s)
    {
        if(i==v.size())
        {
            if(s1==s2 && s2==s3 && s3==s4)
                return true;
            
            return false;
        }
        bool b1=false;
        
        if(s1>s || s2>s || s3>s || s4>s )
            return false;
        if(s1+v[i]<=s)
        b1=find(s1+v[i],s2,s3,s4,v,i+1,s);
        
        if(b1)
        {
            return b1;
        }
        
        if(s2+v[i]<=s)
        b1=find(s1,s2+v[i],s3,s4,v,i+1,s);
        
        if(b1)
            return b1;
        
        if(s3+v[i]<=s)
        b1=find(s1,s2,s3+v[i],s4,v,i+1,s);
        
        if(b1)
            return b1;
        
        if(s4+v[i]<=s)
        b1=find(s1,s2,s3,s4+v[i],v,i+1,s);
        
        if(b1)
            return b1;
        
        return false;
        
    }
        
    
    bool makesquare(vector<int>& ms) {
        int n=ms.size();
        int sum=0;
        int side=0;
        sort(ms.rbegin(),ms.rend());
        for(int i=0;i<n;i++)
        {
            sum+=ms[i];
            
        }
        if(n<4)
        {
            return false;
        }
        if(sum%4!=0)
            return false;
        side=sum/4;
        bool ans=find(0,0,0,0,ms,0,side);
        return ans;
        
    }
};