class Solution {
public:
    
    #define bb "\n"
    
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row=mat.size();
        int col=mat[0].size();
        
        vector<vector<int>>ans;
        vector<int>v;
        if(r*c!=row*col)
        {
            return mat;
        }
        int r1=0,c1=0;
        cout<<col<<" "<<bb;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(c1>=col)
                {
                    c1=0;
                    r1++;
                }
                if(r1>=row)
                {
                    break;
                }
                
                v.push_back(mat[r1][c1]);
                c1++;
            }
            ans.push_back(v);
            v.clear();
        }
        
        return ans;
        
    }
};