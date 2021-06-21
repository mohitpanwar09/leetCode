class Solution {
public:
    vector<vector<int>> generate(int nR) {
        
        vector<vector<int>>ans;
        vector<int>row;
        if(nR>1)
        {
            ans.push_back({1});
        }
        else
        {   
            ans.push_back({1});
            return ans;
        }
        if(nR>=2)
        {
            ans.push_back({1,1});
        }
        
        for(int i=2;i<nR;i++)
        {
            row.push_back(1);
            
            for(int j=1;j<ans[i-1].size();j++)
            {
                row.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            
            row.push_back(1);
            
            ans.push_back(row);
            row.clear();
        }
        
        return ans;
    }
};