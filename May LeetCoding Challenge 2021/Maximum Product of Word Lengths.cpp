class Solution {
    
public:

    
    int maxProduct(vector<string>& wd) {

        map<char,bool>v;
        string str1="";
        bool sl=true;
        int ans=0;
        
        //sort(wd.begin(),wd.end());
        
        for(int i=0;i<wd.size();i++)
        {
           
                for(int k=0;k<wd[i].length();k++)
                {
                    v[wd[i][k]]=true; 
                    // cout<<v[wd[i][k]-'a']<<endl;   
                }
  
                
                for(int j=i;j<wd.size();j++)
                {
                    
                    for(int k=0;k<wd[j].length();k++)
                    {
                        if(v.find(wd[j][k])!=v.end())
                        {
                            sl=false;
                            break;
                        }
                    }
                    
                    if(sl)
                    {
                        if(str1.length()<wd[j].length())
                        str1=wd[j];
                        
                    }
                    sl=true;
                    
                }
            if(ans<wd[i].length()*str1.length())
                ans=wd[i].length()*str1.length();
            
                str1="";
                v.clear();

        }
        
             
        return ans;
    }
    
};