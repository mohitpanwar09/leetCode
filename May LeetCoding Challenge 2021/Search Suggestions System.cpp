class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pd, string sW) {
        
        vector<vector<string>> ans;
        vector<string>v;
        sort(pd.begin(),pd.end());
        
        string str;
        for(int i=1;i<=sW.length();i++)
        {
            str=sW.substr(0,i);
            for(int j=0;j<pd.size();j++)
            {
                string st=pd[j].substr(0,i);
                if(v.size()==3)
                    break;
                if(str==st)
                {
                    v.push_back(pd[j]);
                }
            }
            ans.push_back(v);
            v.clear();
        }
        
        
        return ans;
        
    }
};