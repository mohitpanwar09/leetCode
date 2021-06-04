class Solution {
public:
    
    void findSubSet(string s, queue<string>& q)
    {
        for(int i=0;i<4;i++)
        {
            char c=s[i];
            s[i]=(c-'0' + 1) % 10 + '0';
            q.push(s);
            s[i]=(c-'0' - 1 + 10) % 10 + '0';
            q.push(s);
            s[i]=c; 
        }
    }
    
    int openLock(vector<string>& des, string tg) {
        
        unordered_set <string> dd(des.begin(),des.end());
        unordered_set <string> vist;
        
        queue<string> q;
        q.push("0000");
        
        int lev=0;
        
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                string cur=q.front();
                q.pop();
                if(cur==tg) 
                    return lev;
                if(dd.count(cur) || vist.count(cur))
                    continue;
                
                vist.insert(cur);
                findSubSet(cur,q);
            }
            
            lev++;
        }
        return -1;
    }
};