class Solution {
public:
    
    #define bb "\n"
    
    int numMatchingSubseq(string s, vector<string>& wd) {
        int ans=0;
        map<char,queue<string>>mp;
        
        for(int i=0;i<s.length();i++)
        {
            queue<string>str;
            mp[s[i]]=str;
        }
        
        for(int i=0;i<wd.size();i++)
        {
            mp[wd[i][0]].push(wd[i]);
        }
        
        for(int i=0;i<s.length();i++)
        {
            
            int j=mp[s[i]].size();
            while(!mp[s[i]].empty() && j--)
            {
                string sq=mp[s[i]].front();
                mp[s[i]].pop();
                // cout<<sq<<bb;
                if(sq.substr(1).length()==0)
                {
                    ans++;
                }else
                {
                    if(mp.find(sq[1])!=mp.end())
                    {
                        mp[sq[1]].push(sq.substr(1));
                    }
                }
            }
            
        }
        
        return ans;
    }
};