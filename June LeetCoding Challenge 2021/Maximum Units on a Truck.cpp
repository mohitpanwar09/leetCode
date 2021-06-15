class Solution {
public:
   static bool sortcol( const vector<int>& v1,
               const vector<int>& v2 ) {
                    return v1[1] > v2[1];
            }
    int maximumUnits(vector<vector<int>>& bt, int ts) {
        sort(bt.begin(),bt.end(),sortcol);
        int n=bt.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(ts>0)
            {
                if(ts>=bt[i][0])
                {
                    ts-=bt[i][0];
                    ans+=bt[i][0]*bt[i][1];
                }
                else
                {
                     ans+=ts*bt[i][1];
                        ts=0;
                    break;
                }
            }
        }
        return ans;
    }
};