class Solution {
public:
    #define bb "\n"
    vector<string>ans;
    void find(int i,int j,int n,string s)
    {
        // base case
        if(i==n && j==2*n)
        {
            ans.push_back(s);
            return;
        }
        
        if(j-i<=n && i!=n)
        {
            s+='(';
            find(i+1,j,n,s);
            int a=s.length()-1;
            s=s.substr(0,a);
        }
        if(j-i<n && j!=2*n)
        {
            s+=')';
            find(i,j+1,n,s);
            int a=s.length()-1;
            s=s.substr(0,a);
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        
        string s="";
        ans.clear();
        find(0,n,n,s);
        return ans;
    }
};