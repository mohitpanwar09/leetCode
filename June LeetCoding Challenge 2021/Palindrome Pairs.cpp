class Solution {
public:
    #define bb  "\n"
    bool check(string s)
    {
        int i=0,j=s.length()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& w) {
        int n=w.size();
        vector<vector<int>>ans;
        map<string,int>mp;
        
        for(int i=0;i<n;i++)
        {   
            mp[w[i]]=i;              
        }
        
        if(mp.find("")!=mp.end())
        {
            int ind=mp[""];
            for(int i=0;i<n;i++)
            {
                if(i==ind)
                    continue;
                
                if(check(w[i]))
                {
                    ans.push_back({ind,i});
                    ans.push_back({i,ind});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            string temp=string(w[i].rbegin(),w[i].rend());
            if(mp.find(temp)!=mp.end() && temp!=w[i])
            {
                    //ans.push_back({mp[temp],i});
                    ans.push_back({i,mp[temp]});
            }
            
        }
        
        for(int i=0;i<w.size();i++)
        {
            for(int j=1;j<w[i].length();j++)
            {
                string pre=w[i].substr(0,j);
                string suf=w[i].substr(j);
                
                if(check(pre))
                {
                    string temp=string(suf.rbegin(),suf.rend());
                    if(mp.find(temp)!=mp.end())
                    {
                        ans.push_back({mp[temp],i});
                    } 
                }
                
                if(check(suf))
                {
                    string temp=string(pre.rbegin(),pre.rend());
                    if(mp.find(temp)!=mp.end())
                    {
                        ans.push_back({i,mp[temp]});
                    } 
                }
            }
        }
        
        return ans;
        
    }
};