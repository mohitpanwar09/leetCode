class Solution {
public:
    #define bb "\n"
    
    int numberOfRounds(string ST, string FT) {
        int sth=(ST[0] - '0');
        sth=sth*10+(ST[1]-'0');
        
        int stm=(ST[3] - '0');
        stm=stm*10+(ST[4]-'0');
        
        int fth=(FT[0] - '0');
        fth=fth*10+(FT[1]-'0');
        
        int ftm=(FT[3] - '0');
        ftm=ftm*10+(FT[4]-'0');
        
        int no=0;
        if(sth==fth)
        {
            if(ftm<stm)
            {
                if(sth==23)
                {
                    sth=0;
                }
                else
                {
                    sth++;
                }
                no++;
            }
        }
        
        while(sth!=fth)
        {
            no++;
            if(sth==23)
            {
                sth=0;
                continue;
            }
            sth++;
        }
        
        int ans=0;
        int mi=stm%15?(stm/15) +1:stm/15;
        int pl=(ftm/15);
        ans=no*4 -mi + pl;
        
        
        return ans;
    }
};