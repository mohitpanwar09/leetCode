class Solution {
public:
    map<string ,bool>mp;
    
    bool check(int i,int j,string s1,string s2,int m,string s3)
    {
        // base case
        if(i>s1.length() && j>s2.length())
        {
            return false;
        }
        
        string key=to_string(i)+"*"+to_string(j)+"*"+to_string(m);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        if(m==s3.length()-1)
        {
           
            if((i<s1.length()-1 || j<s2.length()-1 ) && s1.length()!=0 && s2.length()!=0)
            {
                mp[key]=false;
                return mp[key];
            }
            
            if(i==s1.length()-1 && j==s2.length())
            {
                if(s1[i]==s3[m])
                {
                    mp[key]=true;
                    return mp[key]; 
                }
                   
                else
                {
                     mp[key]=false;
                    return mp[key];
                }
            }
             if(j==s2.length()-1 && i==s1.length())  
            {
                if(s2[j]==s3[m])
                    {
                    mp[key]=true;
                     return mp[key];
                }
                else
                {
                     mp[key]=false;
                return mp[key];
                }
                    
            }
                 mp[key]=false;
                return mp[key];
        }
        if(i==s1.length())
        {
            string s1s=s2.substr(j);
            string s3s=s3.substr(m);
                if(s1s==s3s)
                {
                    mp[key]=true;
                     return mp[key];
                }else
                {
                     mp[key]=false;
                     return mp[key];
                }
        }
        
        if(j==s2.length())
        {
            string s2s=s1.substr(i);
            string s3s=s3.substr(m);
                if(s2s==s3s)
                {
                     mp[key]=true;
                     return mp[key];
                }else
                {
                    mp[key]=false;
                    return mp[key];
                }
        }
        
        // cases
        
        if(s1[i]==s3[m] && s2[j]==s3[m])
        {
            bool s1Send=check(i+1,j,s1,s2,m+1,s3);
            bool s2Send=false;
            if(!s1Send)
            {
                s2Send=check(i,j+1,s1,s2,m+1,s3);
            }
            
            mp[key]=max(s1Send,s2Send);
            return mp[key];
        }
        
        if(s1[i]==s3[m])
        {
            mp[key]=check(i+1,j,s1,s2,m+1,s3);
            return mp[key];
        }
        if(s2[j]==s3[m])
        {
            mp[key]=check(i,j+1,s1,s2,m+1,s3);
            return mp[key];
        }
        
        mp[key]=false;
        return mp[key];
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s1.length()+s2.length()!=s3.length())
        {
            return false;
        }
       return check(0,0,s1,s2,0,s3);
    }
};

