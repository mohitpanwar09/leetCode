class Solution {
public:
    bool judgeCircle(string m) {
        int x=0,y=0;
        for(int i=0;i<m.length();i++)
        {
            if(m[i]=='L')
                x-=1;
            if(m[i]=='R')
                x+=1;
            if(m[i]=='U')
                y+=1;
            if(m[i]=='D')
                y-=1;
        
        }
        if(x!=0 || y!=0)
            return false;
        
        return true;
    }
};